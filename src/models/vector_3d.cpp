#include "vector_3d.h"

Vector3D::Vector3D() {}

Vector3D::Vector3D(float *x, float *y, float *z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3D::get_norme()
{
    return 2;
}