#include "triangle_2d.h"

Triangle2D::Triangle2D(Vector2D vectorX, Vector2D vectorY, Vector2D vectorZ)
{
    GLfloat vertex_buffer_data[] = {
        // X
        vectorX.x,
        vectorX.y,
        0.0f,

        // Y
        vectorY.x,
        vectorY.y,
        0.0f,

        // Z
        vectorZ.x,
        vectorZ.y,
        0.0f,
    };

    for (int i = 0; i < 9; i++)
    {
        this->g_vertex_buffer_data[i] = vertex_buffer_data[i];
    }
}

Triangle2D::~Triangle2D()
{
}

void Triangle2D::draw()
{
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,        // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0,        // stride
        (void *)0 // array buffer offset
    );
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}