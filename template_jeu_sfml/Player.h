#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
public:
	Player(double x = 0.0, double y = 0.0);

	void update(float deltaTime) override;

	double m_posX;
	double m_posY;
    double m_speed; // norme de la vitesse
	double m_speedX;
	double m_speedY;

	double m_angle;

	

	/*double getPosX() const;
	double getPosY() const;*/
    void compute_speed();

};

#endif // !PLAYER_H
