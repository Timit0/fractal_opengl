#include "line.h"

const char *vertexShaderSource = "#version 430\n"
                                 "in vec3 pos;"
                                 "void main() {"
                                 "gl_Position = vec4(pos, 1);"
                                 "}";

const char *fragmentShaderSource = "#version 430\n"
                                   "void main() {"
                                   "gl_FragColor = vec4(1, 0, 0, 1);"
                                   "}";

Line::Line()
{
}

Line::Line(Vector2D start, Vector2D end)
{
    this->start = start;
    this->end = end;
}

Line::~Line() {};

void Line::Draw()
{
    GLfloat vertices[] =
        {
            this->start.x,
            this->start.y,
            0,
            this->end.x,
            this->end.y,
            0,
        };

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glClearColor(0.07, 0.13, 0.17, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE, 0, 2);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}