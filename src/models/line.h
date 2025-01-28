#include <iostream>
#include "vector_2d.h"
// #include "GLFW/glfw3.h"

class Line
{
public:
    Line();
    Line(Vector2D start, Vector2D end);
    ~Line();
    void Draw();

protected:
    Vector2D start;
    Vector2D end;
};