#include <GameWindow.h>
#include <iostream>
#include <cmath>

GameWindow::GameWindow()
{
    // Charge l'image qui remplacera le rond jaune.
    // Le fichier doit se trouver à côté de l'exécutable (voir CMakeLists.txt).
    std::string imagePath = std::string("Images/animal_linux_penguin_2598.png");
    if (playerTexture.loadFromFile(imagePath))
    {
        playerSprite.emplace(playerTexture);
    }
    else
    {
        std::cout << "Impossible de charger " << imagePath << ", le cercle jaune sera utilise a la place." << std::endl;
    }
}

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

// we should add every forces that we create in the sum
float GameWindow::get_forcesX() {
    return gravity[0];
}
float GameWindow::get_forcesY() {
    return gravity[1];
}

void GameWindow::show(int width, int height, const std::string& title)
{
    _window.create(sf::VideoMode(sf::Vector2u(width, height)), title);

    _window.setFramerateLimit(framerate);

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

	double dt = 1.0 / framerate; // time between two frames in seconds

	double deltaX = playerX - playerbeforeX;
	double deltaY = playerY - playerbeforeY;

	double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

	double vitesse = distance / dt; // vitesse = distance / temps

    static sf::Font font;
    static bool fontLoaded = font.openFromFile("arial.ttf"); 

    if (fontLoaded) {
        sf::Text textVitesse(font);
        textVitesse.setCharacterSize(18);
        textVitesse.setFillColor(sf::Color::Red);
        textVitesse.setPosition(sf::Vector2f(10.f, 10.f));
        textVitesse.setString("Speed : " + std::to_string(vitesse) + " units/sec");
        _window.draw(textVitesse);
    }
    else { std::cout << "Speed : " << vitesse << " units/sec" << std::endl; } // Print speed to console if font is not loaded



#endif

    // Draw player
    int radius = 10;

    //zoom factor
    double z = 1.0; // Adjust this value to change the zoom level

    //player position in screen coordinates
    WorldPoint playerPosition = { playerX, playerY };

    // Convert player position to screen coordinates
    ScreenPoint playerScreenPosition = toScreen(playerPosition, screen_res.x, screen_res.y, z);

    if (playerSprite)
    {
        // Centre l'origine du sprite sur son propre centre, pour que
        // setPosition() positionne le CENTRE de l'image (comme le cercle avant).
        sf::Vector2u texSize = playerTexture.getSize();
        playerSprite->setOrigin(sf::Vector2f(texSize.x / 2.f, texSize.y / 2.f));

        // Optionnel : redimensionne l'image pour qu'elle fasse environ 2*radius de large.
        // Commente ces deux lignes si tu veux garder la taille originale de l'image.
        float scale = (radius * 2.f) / static_cast<float>(texSize.x);
        playerSprite->setScale(sf::Vector2f(scale, scale));

        // --- Rotation selon la direction de deplacement ---
        // (playerAngleDeg est calcule dans update(), pas ici : render() se contente
        // de lire l'etat du jeu et de dessiner, il ne doit pas contenir de logique.)

        // ROTATION_OFFSET : a ajuster selon l'orientation de base de ton image.
        // Si l'image regarde vers la DROITE par defaut -> laisse 0.
        // Si elle regarde vers le HAUT par defaut       -> mets 90.
        // Si elle regarde vers la GAUCHE par defaut      -> mets 180.
        // Si elle regarde vers le BAS par defaut         -> mets -90 (ou 270).
        constexpr float ROTATION_OFFSET = 90.f;

        playerSprite->setRotation(sf::degrees(playerAngleDeg + ROTATION_OFFSET));

        playerSprite->setPosition(sf::Vector2f(playerScreenPosition.first, playerScreenPosition.second));

        _window.draw(*playerSprite);
    }
    else
    {
        //create player circle shape
        sf::CircleShape circle(radius);

        circle.setFillColor(sf::Color::Yellow);

        circle.setPosition(sf::Vector2f(playerScreenPosition.first - radius, playerScreenPosition.second - radius));

        _window.draw(circle);
    }

    _window.display();
}

void GameWindow::update()
{
	playerbeforeX = playerX;
    playerbeforeY = playerY;

    // calculating delta_t (time elapsed since last frame)
    std::chrono::duration<double> delta_t = std::chrono::high_resolution_clock::now() - last_frame_time;
    double delta_t_sec = delta_t.count();
    // updating time of the last frame for the next update
    last_frame_time = std::chrono::high_resolution_clock::now();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        // playerX -= 1.0;
        player_speedX -= (get_forcesX() / mass) * delta_t_sec;
        playerX -= player_speedX * delta_t_sec + playerX;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        // playerX += 1.0;
        player_speedX += (get_forcesX() / mass) * delta_t_sec;
        playerX += player_speedX * delta_t_sec + playerX;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        // playerY -= 1.0;
        player_speedY -= (get_forcesY() / mass) * delta_t_sec;
        playerY -= player_speedY * delta_t_sec + playerY;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        // playerY += 1.0;
        player_speedY += (get_forcesY() / mass) * delta_t_sec;
        playerY += player_speedY * delta_t_sec + playerY;
    }

    // --- Direction de deplacement (utilisee par render() pour orienter le sprite) ---
    double deltaX = playerX - playerbeforeX;
    double deltaY = playerY - playerbeforeY;
    double moveDistance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    const double MOVE_THRESHOLD = 0.001;

    if (moveDistance > MOVE_THRESHOLD)
    {
        constexpr double PI = 3.14159265358979323846;
        playerAngleDeg = static_cast<float>(std::atan2(deltaY, deltaX) * 180.0 / PI);
    }
}
