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

	double m_posX;
	double m_posY;
	double m_speedX;
	double m_speedY;

	double m_angle;

	

	/*double getPosX() const;
	double getPosY() const;*/


};

#endif // !PLAYER_H
