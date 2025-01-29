#include <iostream>

#define GLFW_INCLUDE_NONE
#include "glad/gl.h"
#include "GLFW/glfw3.h"
// #include "models/line.h"

int main()
{
    if (!glfwInit())
    {
        // Initialization failed
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow *window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        // Window or OpenGL context creation failed
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glfwMakeContextCurrent(window);

    gladLoadGL(glfwGetProcAddress);

    while (!glfwWindowShouldClose(window))
    {
        // Keep running
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}