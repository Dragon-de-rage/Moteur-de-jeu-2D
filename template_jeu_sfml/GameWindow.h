#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <array>

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

	double playerX = 0.0;
	double playerY = 0.0;

	double playerbeforeX = 0.0;
	double playerbeforeY = 0.0;

    double player_speedX = 0.0;
    double player_speedY = 0.0;

    int framerate = 50;

    time_point last_frame_time = std::chrono::high_resolution_clock::now();

    void show(int width, int height, const std::string& title);


    // Forces applied to characters
    // They are vectors, X and Y norms are in Newtons
    // Use get_forcesX() and ...Y() function to get all the forces applied on one axis
    std::array<float, 2> gravity = {0.0f, 10.0f};

    // Player mass (in kilograms)
    float mass = 500;

private:

    sf::RenderWindow _window;

    void processEvents();
    void render();

    float get_forcesX();
    float get_forcesY();

    void update();
};

#endif

