#ifndef KOCH_CURVE_H
#define KOCH_CURVE_H

#include "line/line_2d.h"
#include <math.h>

class KochCurve
{
public:
    KochCurve() = default;
    KochCurve(float x1, float x2, float y1, float y2, int depth);
    void draw();
    void draw_fractal(float x1, float x2, float y1, float y2, int depth);

protected:
    float x1;
    float x2;
    float y1;
    float y2;
    int depth;
};
#endif