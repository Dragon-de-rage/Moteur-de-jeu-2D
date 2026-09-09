#include <GameWindow.h>

GameWindow::GameWindow()
{
}

void GameWindow::show(int width, int height, const std::string& title)
{
    _window.create(sf::VideoMode(width, height), title);

    while (_window.isOpen())
    {
        processEvents();
        render();
    }
}

void GameWindow::processEvents()
{
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
            {
                // Left key pressed.
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                // Right key pressed.
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                // Up key pressed.
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                // Down key pressed.
            }
        }
    }
}

void GameWindow::render()
{
    // Clear background with White color.
    _window.clear(sf::Color::White);

    // Draw player as a yellow circle.
    int radius = 10;

    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(100 - radius, 100 - radius);

    _window.draw(circle);

    _window.display();
}
