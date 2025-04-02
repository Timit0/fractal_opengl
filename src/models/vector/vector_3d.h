#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include "vector.h"

class Vector3D : public Vector
{
public:
    float *x;
    float *y;
    float *z;

    Vector3D();
    Vector3D(float *x, float *y, float *z);

    float get_norme() override;
};
#endif