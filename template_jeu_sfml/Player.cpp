#include "Player.h"

Player::Player(double x, double y)
	: m_posX(x), m_posY(y), m_angle(0.0), m_speedX(0.0), m_speedY(0.0)
{
	m_textureFile = "Images/animal_linux_penguin_2598.png";
	setTexture();
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

void Player::setKeyBinding(const KeyBinding& binding)
{
	m_keyBinding = binding;
}

void Player::setKey(PlayerAction action, sf::Keyboard::Key key)
{	
	m_keyBinding[action] = key;
}

bool Player::isKeyPressed(PlayerAction action)
{
	if (!m_keyBinding.contains(action))
		return false;
	return sf::Keyboard::isKeyPressed(m_keyBinding.at(action));
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