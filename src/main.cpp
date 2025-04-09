#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <map>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

#include "line/line_2d.h"
#include "triangle/triangle_2d.h"
#include "settings/settings.h"
#include "fractal/koch_curve.h"
#include "app/app.h"

const double MAX_FPS = 60;

GLFWwindow *window;
GLFWmonitor *monitor;
bool running = true;

App *app = new App();

void update(double delta), input(), draw();
static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

int main()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    if (!glfwInit())
        fprintf(stderr, "Failed to init GLFW\n");
    window = glfwCreateWindow(app->WIDTH, app->HEIGHT, "Fractal", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "FAILED to open window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    monitor = glfwGetPrimaryMonitor();

    app->set_window(window);
    app->set_monitor(monitor);

    if (app->get_fullscreen())
    {
        std::cout << "FULLSCREEN" << std::endl;
        glfwSetWindowMonitor(window, monitor, 100, 100, app->WIDTH, app->HEIGHT, 0);
    }
    else
    {
        std::cout << "WINDOWED" << std::endl;
        glfwSetWindowMonitor(window, nullptr, 100, 100, app->WIDTH, app->HEIGHT, 0);
    }

    double lastTime = 0.0;

    GLuint programID = app->load_shaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

    // Creation of objects
    KochCurve *kochCurve = new KochCurve(-0.5f, 0.5f, 0.0f, 0.0f, 5);
    //

    while (!glfwWindowShouldClose(window))
    {
        double time = glfwGetTime();
        double deltaTime = time - lastTime;
        if (deltaTime >= 1 / MAX_FPS)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glUseProgram(programID);
            update(deltaTime);

            kochCurve->draw();

            draw();
            lastTime = time;
        }

        input();
    }

    return 0;
}

void update(double delta)
{
    if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS)
    {
        if (Settings::zoom <= 1)
        {
            Settings::zoom += Settings::zoom_range;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
    {
        if (Settings::zoom >= 0)
        {
            Settings::zoom -= Settings::zoom_range;
        }
    }
}

void d()
{
    if (window != NULL)
    {
        return;
    }
    app->toggle_fullscreen();
    if (!app->get_fullscreen())
    {
        glfwSetWindowMonitor(window, nullptr, 100, 100, app->WIDTH, app->HEIGHT, 0);
    }
    else
    {
        glfwSetWindowMonitor(window, monitor, 100, 100, app->WIDTH, app->HEIGHT, 0);
    }
}

void input()
{
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        running = false;
        glfwSetWindowShouldClose(window, 1);
    }

    app->on_pressed_once(
        []()
        {
            app->toggle_fullscreen();
            if (!app->get_fullscreen())
            {
                glfwSetWindowMonitor(window, nullptr, 100, 100, app->WIDTH, app->HEIGHT, 0);
            }
            else
            {
                glfwSetWindowMonitor(window, monitor, 100, 100, app->WIDTH, app->HEIGHT, 0);
            }
        },
        GLFW_KEY_F11);

    glfwSetCursorPosCallback(window, cursor_position_callback);
}

void draw()
{
    glfwSwapBuffers(window);
}

static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
    // std::cout << "Position: (" << xpos << ":" << ypos << ")";
}
