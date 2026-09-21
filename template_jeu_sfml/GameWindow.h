#pragma once

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <array>
#include <optional>

using ScreenPoint = std::pair<int, int>;
using WorldPoint = std::pair<double, double>;

ScreenPoint toScreen(const WorldPoint& point, int W, int H, double z);
WorldPoint toWorld(const ScreenPoint& point, int W, int H, double z);

using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;

class GameWindow
{
public:
    GameWindow();

    // Show window.
    // Input:
    //  * width: window width (pixels).
    //  * height: window height (pixels).
    //  * title: window title.
    // Output:
    //  * Nothing.

    // position joueur
	double playerbeforeX = 0.0;
	double playerbeforeY = 0.0;

    time_point last_frame_time = std::chrono::high_resolution_clock::now();

    void show(int width, int height, const std::string& title);

    std::string background = "";

    // Forces applied to characters
    // They are either const or vectors, X and Y norms are in Newtons
    // Use get_forcesX() and ...Y() function to get all the forces applied on one axis
    std::array<const double, 2> gravity = {0.0, 9.80665};
    // constantes (plus tard paramétrable dans moteur)
    double propulsion = 100000.0;
    double coef_frottements = 5.0;
    double masse_volumique_atmo = 1.225;

    // Player mass (in kilograms)
    double mass = 1000.0;

private:

    sf::RenderWindow _window;

    void processEvents();
    void render();

    double get_forcesX();
    double get_forcesY();
    double compute_friction(double speed);
	double compute_delta_t();

    void update();
};

#endif

