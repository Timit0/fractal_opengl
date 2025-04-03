#ifndef LINE_H
#define LINE_H

#include <iostream>

#include "glad/gl.h"
#include <GLFW/glfw3.h>

class Line
{
public:
    virtual void draw() = 0;
};
#endif