#pragma once
#ifndef RECTANGULARCOLLISION_H
#define RECTANGULARCOLLISION_H

#include "Collision.h"

class RectangularCollision : Collision // rectangular collisions as for now
{
    double m_width;
    double m_height;

public:
    RectangularCollision(double x, double y, double width, double height);
    //getters
    double Width() { return m_width; }
    double Height() { return m_height; }

    bool is_colliding(Collision* collider, auto callback = []() -> void { return; });
};

#endif // RECTANGULARCOLLISION_H
