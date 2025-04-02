#ifndef TRIANGLE_2D_H
#define TRIANGLE_2D_H

#include "triangle.h"
#include "vector/vector_3d.h"
#include <vector>
#include <fstream>
#include <sstream>

class Triangle2D : Triangle
{
public:
    Triangle2D(Vector2D vectorX, Vector2D vectorY, Vector2D vectorZ);
    ~Triangle2D();

    void draw() override;

protected:
    Vector2D vectorX;
    Vector2D vectorY;
    Vector2D vectorZ;
    GLfloat g_vertex_buffer_data[9];
};
#endif