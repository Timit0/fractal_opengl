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

    float xA = x1 + (x2 - x1) / 3.0;
    float yA = y1 + (y2 - y1) / 3.0;

    float xB = x1 + 2.0 * (x2 - x1) / 3.0;
    float yB = y1 + 2.0 * (y2 - y1) / 3.0;

    float dx = xB - xA;
    float dy = yB - yA;

    float xPeak = (xA + xB) / 2.0 - sqrt(3) * (yB - yA) / 6.0;
    float yPeak = (yA + yB) / 2.0 + sqrt(3) * (xB - xA) / 6.0;

    draw_fractal(x1, xA, y1, yA, depth - 1);
    draw_fractal(xA, xPeak, yA, yPeak, depth - 1);
    draw_fractal(xPeak, xB, yPeak, yB, depth - 1);
    draw_fractal(xB, x2, yB, y2, depth - 1);
}
