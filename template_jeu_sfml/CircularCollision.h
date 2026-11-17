#pragma once
#ifndef CIRCULARCOLLISION_H
#define CIRCULARCOLLISION_H

#include "Collision.h"

class CircularCollision : public Collision
{
    double m_radius;
public:
    CircularCollision(double x, double y, double radius);
    //getters
    double Radius() { return m_radius; }

    bool is_colliding(Collision* collider, auto callback = []() -> void { return; });
};

#endif // CIRCULARCOLLISION_H
