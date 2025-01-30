#include "vector_2d.h"

Vector2D::Vector2D() {}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2D::get_norme()
{
    return 2;
}