#include "line_2d.h"

Line2D::Line2D() {}

Line2D::Line2D(Vector2D start, Vector2D end)
{
    this->start = start;
    this->end = end;

    update_buffer_data();

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
}

Line2D::~Line2D()
{
    glDeleteBuffers(1, &vertexbuffer);
}

void Line2D::draw()
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glDrawArrays(GL_LINES, 0, 2);
}

Vector2D Line2D::get_start_vector()
{
    return this->start;
}

Vector2D Line2D::get_end_vector()
{
    return this->end;
}

Line2D Line2D::set_start(Vector2D newVector)
{
    this->start = newVector;
    update_buffer_data();
}

Line2D Line2D::set_end(Vector2D newVector)
{
    this->end = newVector;
    update_buffer_data();
}

Line2D Line2D::update_buffer_data()
{
    GLfloat vertex_buffer_data[] = {
        this->start.x,
        this->start.y,
        0.0f,

        this->end.x,
        this->end.y,
        0.0f,
    };

    for (int i = 0; i < 6; i++)
    {
        this->g_vertex_buffer_data[i] = vertex_buffer_data[i];
    }
}