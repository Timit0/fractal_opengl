#ifndef LINE_2D_H
#define LINE_2D_H

#include "line.h"
#include "vector/vector_2d.h"

class Line2D : Line
{
public:
    void draw() override;
    Line2D();
    Line2D(Vector2D start, Vector2D end);
    ~Line2D();
    Vector2D get_start_vector();
    Vector2D get_end_vector();
    Line2D set_start(Vector2D newVector);
    Line2D set_end(Vector2D newVector);

protected:
    Vector2D start;
    Vector2D end;
    GLfloat g_vertex_buffer_data[6];
    GLuint vertexbuffer;
    Line2D update_buffer_data();
};
#endif