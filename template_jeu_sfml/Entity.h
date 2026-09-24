#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
	// Update physics and logic
	virtual void update(float deltaTime) = 0;
	// Drow the entity on the window
	virtual void render(sf::RenderWindow& window) = 0;

	void setTexture(const std::string& textureFile);

	[[nodiscard]] bool isColliding(const Entity& other) const;

	std::optional<sf::Sprite> m_sprite;

private:
	sf::Texture m_texture;
	

protected:
	std::string m_textureFile;
};

#endif