#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "PlayerAction.h"

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

	// Set each player's key binding
	void setKeyBinding(const KeyBinding& binding);

	// Set each keys
	void setKey(PlayerAction action, sf::Keyboard::Key key);

	/*double getPosX() const;
    double getPosY() const;*/
    void compute_speed();

private:
	bool isKeyPressed(PlayerAction action);

	KeyBinding m_keyBinding;
};

#endif // !PLAYER_H
