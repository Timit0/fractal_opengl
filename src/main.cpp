#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <map>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include "models/line.h"

const float WIDTH = 1280;
const float HEIGHT = 720;

const double MAX_FPS = 60;

GLFWwindow *window;
GLFWmonitor *monitor;
bool running = true, fullscreen;

void update(double delta), input(), draw();

int main()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    if (!glfwInit())
        fprintf(stderr, "Failed to init GLFW\n");
    window = glfwCreateWindow(WIDTH, HEIGHT, "Fractal", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "FAILED to open window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    monitor = glfwGetPrimaryMonitor();
    running = true;
    fullscreen = false;

    double lastTime = 0.0;

    while (running)
    {
        double time = glfwGetTime();
        double deltaTime = time - lastTime;
        if (deltaTime >= 1 / MAX_FPS)
        {
            update(deltaTime);
            draw();
            lastTime = time;
        }

        input();
    }

    return 0;
}

void update(double delta)
{
    Line *line = new Line(Vector2D(200, 100), Vector2D(100, 300));
    line->Draw();
    delete line;
}

void input()
{
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        running = false;
        glfwSetWindowShouldClose(window, 1);
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        if (!fullscreen)
            glfwSetWindowMonitor(window, monitor, 0, 0, WIDTH, HEIGHT, 0);
        if (fullscreen)
            glfwSetWindowMonitor(window, NULL, 0, 0, WIDTH, HEIGHT, 0);
    }
}

void draw()
{
    glfwSwapBuffers(window);
}