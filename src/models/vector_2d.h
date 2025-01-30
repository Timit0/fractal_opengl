#include "vector.h"

class Vector2D : public Vector
{
public:
    float x;
    float y;

    Vector2D();
    Vector2D(float x, float y);

    float get_norme() override;
};