#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <string>



using ScreenPoint = std::pair<int, int>;
using WorldPoint = std::pair<double, double>;

ScreenPoint toScreen(const WorldPoint& point, int W, int H, double z);
WorldPoint toWorld(const ScreenPoint& point, int W, int H, double z);



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

    void show(int width, int height, const std::string& title);

private:

    sf::RenderWindow _window;

    void processEvents();
    void render();
};

#endif

