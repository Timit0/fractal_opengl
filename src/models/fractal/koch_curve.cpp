#include "koch_curve.h"

KochCurve::KochCurve(float x1, float x2, float y1, float y2, int depth)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->depth = depth;
}

void KochCurve::draw()
{
    draw_fractal(this->x1, this->x2, this->y1, this->y2, this->depth);
}

void KochCurve::draw_fractal(float x1, float x2, float y1, float y2, int depth)
{
    if (depth == 0)
    {
        Line2D *pLine1 = new Line2D(Vector2D(x1, y1), Vector2D(x2, y2));
        pLine1->draw();
        delete pLine1;
        return;
    }

    draw_fractal(x1, x2, y1, y2, depth - 1);
}
