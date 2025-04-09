#ifndef APP_H
#define APP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>

#include "glad/gl.h"
#include "GLFW/glfw3.h"

class App
{
public:
    App() = default;
    App(GLFWwindow *window, GLFWmonitor *monitor);
    App(bool titleBarState, bool fullscreen, bool inputInUsageState);
    ~App();

    const float WIDTH = 1280;
    const float HEIGHT = 720;

    GLuint load_shaders(const char *vertex_file_path, const char *fragment_file_path);

    bool get_title_bar_state();
    App *toggle_title_bar_state();

    bool get_fullscreen();
    App *toggle_fullscreen();

    bool get_input_in_usage_state();
    App *toggle_input_in_usage_state();

    int get_actual_input();
    App *set_actual_input(int input);

    App *set_window(GLFWwindow *window);
    App *set_monitor(GLFWmonitor *monitor);

    void on_pressed_once(std::function<void()> func, int input);

protected:
    bool titleBarState = true;
    bool fullscreen = false;
    bool inputInUsageState = false;
    int actualInput = -1;
    GLFWwindow *window;
    GLFWmonitor *monitor;
};
#endif