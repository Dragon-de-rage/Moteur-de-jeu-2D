#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
	// Update physics and logic
    virtual void update(float deltaTime) = 0;

    virtual void draw(std::pair<int, int> screenPoint, sf::RenderWindow* window);

    void setTexture(sf::Vector2f scale);

    [[nodiscard]] bool isColliding(const Entity& other) const;

	std::optional<sf::Sprite> m_sprite;

protected:
	std::string m_textureFile;
	sf::Texture m_texture;
    double m_posX;
    double m_posY;
    double m_angle;
    int radius = 10;

public :
    double get_pos_X();
    double get_pos_Y();
    double get_angle();

};

#endif