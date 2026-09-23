#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <chrono>

class Player : public Entity
{
public:
	Player(double x = 0.0, double y = 0.0);

	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;

	double m_posX;
	double m_posY;
	double m_speedX;
	double m_speedY;

	double m_angle;

	

	/*double getPosX() const;
	double getPosY() const;*/

private:
	std::string Entity::m_textureFile = "Images/animal_linux_penguin_2598.png";


};

#endif // !PLAYER_H
