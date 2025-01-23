#include <iostream>
#include "GLFW/glfw3.h"

int main()
{
    GLFWwindow *window;

    if (!glfwInit())
    {
        std::cout << "GLFW Not Initialized" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(800, 450, "fractal", 0, 0);

    if (!window)
    {
        std::cout << "Windows was not created" << std::endl;
        return -1;
    }
    while (true)
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}