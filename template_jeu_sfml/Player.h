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

    double mass = 1000.0;

	double m_angle;

	// Set each player's key binding
	void setKeyBinding(const KeyBinding& binding);

	// Set each keys
	void setKey(PlayerAction action, sf::Keyboard::Key key);

	/*double getPosX() const;
    double getPosY() const;*/
    void compute_speed();
    void compute_movement(double& coef_frottements, double& masse_volumique_atmo, double& current_dt, const double& forces_X, const double& forces_Y,
                          double& zoom_factor, const sf::Vector2u& screen_res);
    void compute_border_collision(const sf::Vector2u& screen_res, double zoom_factor, double current_dt);

    // getters
    double get_pos_X();
    double get_pos_Y();
    double get_player_before_X();
    double get_player_before_Y();
    // double get_speed_X();
    // double get_speed_Y();
    double compute_and_get_speed();

private:
	bool isKeyPressed(PlayerAction action);

    double m_posX;
    double m_posY;
    double m_speed; // norme de la vitesse
    double m_speedX;
    double m_speedY;
    double radius = 10;

    double player_before_X = 0.0;
    double player_before_Y = 0.0;
    double propulsion = 100000.0;

	KeyBinding m_keyBinding;
};

#endif // !PLAYER_H
