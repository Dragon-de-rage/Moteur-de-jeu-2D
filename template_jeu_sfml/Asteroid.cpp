#include "Asteroid.h"

Asteroid::Asteroid(double x, double y)
{
    m_posX = x;
    m_posY = y;
    m_angle = 0.0;
    m_textureFile = "Images/asteroid2_96201.png";
    setTexture(sf::Vector2f(0.3, 0.3));
}

void Asteroid::update(float deltaTime)
{
    m_angle += 5 * deltaTime;
}
