#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "vector/vector_2d.h"

#include "glad/gl.h"
#include <GLFW/glfw3.h>

class Line
{
public:
    Line();
    Line(Vector2D start, Vector2D end);
    ~Line();
    void draw();
    Vector2D get_start_vector();
    Vector2D get_end_vector();

protected:
    Vector2D start;
    Vector2D end;
};
#endif