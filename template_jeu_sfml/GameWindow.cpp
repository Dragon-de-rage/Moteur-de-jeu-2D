#include <GameWindow.h>

GameWindow::GameWindow()
{}

ScreenPoint toScreen(const WorldPoint& point, int W, int H, double z)
{
    int X = W / 2 + point.first * z;
    int Y = H / 2 + point.second * z;

    return { X, Y };
}

WorldPoint toWorld(const ScreenPoint& point, int W, int H, double z)
{
    double X = (point.first - W / 2) / z;
    double Y = (H / 2 - point.second) / z;

    return { X, Y };
}


void GameWindow::show(int width, int height, const std::string& title)
{
    _window.create(sf::VideoMode(sf::Vector2u(width, height)), title);

    _window.setFramerateLimit(50);

    while (_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void GameWindow::processEvents()
{

    while (auto event = _window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            _window.close();
        }
        /*
        if (event->is<sf::Event::KeyPressed>())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                playerX -= 1.0; // Move player left
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                playerX += 1.0; // Move player right
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                playerY -= 1.0; // Move player up
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                playerY += 1.0; // Move player down
            }
        }*/
    }
}

void GameWindow::render()
{
    // Clear background with White color.
    _window.clear(sf::Color::White);
    sf::Vector2u screen_res = _window.getSize();
#ifdef SFML_DEBUG // if in debug, prints the axis
    sf::Vector2u screen_res = _window.getSize();
    float y = screen_res.y; // because screen_res.y is an uint
    sf::RectangleShape axe_x(sf::Vector2f(screen_res.x, 1));
    sf::RectangleShape axe_y(sf::Vector2f(1, -y));
    axe_x.setFillColor(sf::Color::Red);
    axe_y.setFillColor(sf::Color::Red);
    axe_x.setPosition(sf::Vector2f(screen_res.x / 2, screen_res.y / 2));
    axe_y.setPosition(sf::Vector2f(screen_res.x / 2, screen_res.y / 2));
    _window.draw(axe_x);
    _window.draw(axe_y);
    // draws graduations each 10 pixels
    sf::RectangleShape graduation(sf::Vector2f(1, 10));
    graduation.setFillColor(sf::Color::Red);
    for (size_t i = 10; i < screen_res.x / 2; i += 10) { // on x axis
        graduation.setPosition(sf::Vector2f(screen_res.x / 2 + i, screen_res.y / 2 - 5));
        _window.draw(graduation);
    }
    graduation.setSize(sf::Vector2f(10, 1));
    for (size_t i = 10; i < screen_res.y / 2; i += 10) { // on x axis
        graduation.setPosition(sf::Vector2f(screen_res.x / 2 - 5, screen_res.y / 2 - i));
        _window.draw(graduation);
    }
#endif

    // Draw player as a yellow circle.
    int radius = 10;

    //zoom factor
    double z = 1.0; // Adjust this value to change the zoom level

    //player position in screen coordinates
    WorldPoint playerPosition = { playerX, playerY };

    // Convert player position to screen coordinates
    ScreenPoint playerScreenPosition = toScreen(playerPosition, screen_res.x, screen_res.y, z);


    //create player circle shape
    sf::CircleShape circle(radius);

    circle.setFillColor(sf::Color::Yellow);

    circle.setPosition(sf::Vector2f(playerScreenPosition.first - radius, playerScreenPosition.second - radius));

    _window.draw(circle);

    _window.display();
}

void GameWindow::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        playerX -= 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        playerX += 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        playerY -= 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        playerY += 1.0;
    }
}
