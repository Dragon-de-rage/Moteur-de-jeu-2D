#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity
{
public:
    Asteroid(double x, double y);
    void update(float deltaTime) override;
};

#endif // ASTEROID_H
