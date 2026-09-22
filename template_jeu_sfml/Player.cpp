#include "Player.h"

Player::Player(double x, double y)
    : m_posX(x), m_posY(y)
{
    // Charger la texture
	double m_angle = 0.0;
	double m_speedX = 0.0;
	double m_speedY = 0.0;
	Entity::setTexture(m_textureFile);
	
}

void Player::update(float deltaTime)
{
    m_posX += m_speedX * deltaTime;
    m_posY += m_speedY * deltaTime;

	if (m_sprite)
	{
		m_sprite->setPosition(sf::Vector2f(m_posX, m_posY));
		m_sprite->setRotation(sf::Angle(sf::radians(m_angle)));
	}
}

void Player::render(sf::RenderWindow& window)
{
    if (!m_sprite) return;
    // Positionner et orienter le sprite : ne pas passer l'angle à setPosition
    m_sprite->setPosition(sf::Vector2f(m_posX, m_posY));
    m_sprite->setRotation(sf::radians(m_angle)); // rotation séparée
		window.draw(*m_sprite);
}

//double Player::getPosX() const
//{
//	return m_posX;
//}
//
//double Player::getPosY() const
//{
//	return m_posY;
//}