#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "vector/vector_2d.h"

#include "glad/gl.h"
#include <GLFW/glfw3.h>

class Triangle
{
public:
    virtual void draw();

protected:
    GLuint VertexArrayID;
};
#endif