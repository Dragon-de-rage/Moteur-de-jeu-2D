#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
	// Update physics and logic
	virtual void update(float deltaTime) = 0;

	void setTexture();

	[[nodiscard]] bool isColliding(const Entity& other) const;

	std::optional<sf::Sprite> m_sprite;

protected:
	std::string m_textureFile;
	sf::Texture m_texture;
    double m_posX;
    double m_posY;
    double m_angle;

public :
    double get_pos_X();
    double get_pos_Y();
    double get_angle();
};

#endif