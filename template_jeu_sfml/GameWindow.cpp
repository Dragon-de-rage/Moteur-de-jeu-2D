#include <GameWindow.h>
#include <iostream>
#include <cmath>

GameWindow::GameWindow()
{
    //!\\ Instancier le joueur
	player = new Player(0.0, 0.0);

	std::string backgroundImagePath = "Images/space-background.jpg";
	if (backgroundTexture.loadFromFile(backgroundImagePath)) {
		backgroundSprite.emplace(backgroundTexture);
	}
	else {
		std::cout << "Erreur lors du chargement de l'image de fond : " << backgroundImagePath << std::endl;
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

// the sum of all vectorial absolute forces
// absolute = not relative to speed or anything
double GameWindow::get_forcesX() {
    return gravity[0]*mass;
}
double GameWindow::get_forcesY() {
    return gravity[1]*mass;
}

// on néglige l'aire du solide selon la direction perpendiculaire à la vitesse S
// le coeff. de frottements est ici utilisé comme le coeff. de traînée
double GameWindow::compute_friction(double speed) {
    return (speed * speed * masse_volumique_atmo * coef_frottements) / 2;
}

double GameWindow::compute_delta_t()
{
    // calculating delta_t (time elapsed since last frame)
    time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> delta_t = now - last_frame_time;
    
    // updating time of the last frame for the next update
    last_frame_time = now;

    return delta_t.count();
}

void GameWindow::compute_border_collision()
{
    //calculate the limits of the player's position based on the screen size and zoom factor
    double xMax = (screen_res.x / 2.0) / zoom_factor - radius;
    double xMin = -xMax;

    double yMax = (screen_res.y / 2.0) / zoom_factor - radius;
    double yMin = -yMax;

    //check if the player is out of bounds and adjust position and speed accordingly
    if (player->m_posX > xMax) {
        double oldX = player->m_posX - player->m_speedX * current_dt;
        double timeToCollision = (xMax - oldX) / player->m_speedX;
        double remainingTime = current_dt - timeToCollision;

        player->m_speedX = -player->m_speedX;

        player->m_posX = xMax + (player->m_speedX * remainingTime);
    }
    else if (player->m_posX < xMin) {
        double oldX = player->m_posX - player->m_speedX * current_dt;
        double timeToCollision = (xMin - oldX) / player->m_speedX;
        double remainingTime = current_dt - timeToCollision;

        player->m_speedX = -player->m_speedX;

        player->m_posX = xMin + (player->m_speedX * remainingTime);
    }

    if (player->m_posY > yMax) {
        double oldY = player->m_posY - player->m_speedY * current_dt;
        double timeToCollision = (yMax - oldY) / player->m_speedY;
        double remainingTime = current_dt - timeToCollision;

        player->m_speedY = -player->m_speedY;

        player->m_posY= player->m_posY + (player->m_speedY * remainingTime);
    }
    else if (player->m_posY < yMin) {
        double oldY = player->m_posY - player->m_speedY * current_dt;
        double timeToCollision = (yMin - oldY) / player->m_speedY;
        double remainingTime = current_dt - timeToCollision;

        player->m_speedY = -player->m_speedY;

        player->m_posY = player->m_posY + (player->m_speedY * remainingTime);
    }
}

void GameWindow::render_debug()
{
    // Debug : draw axes
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

    double deltaX = player->m_posX - playerbeforeX;
    double deltaY = player->m_posY - playerbeforeY;

    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    double vitesse = distance / current_dt; // speed = distance / time

    static sf::Font font;
    static bool fontLoaded = font.openFromFile("arial.ttf");

    double v = std::sqrt(player->m_speedX * player->m_speedX + player->m_speedY * player->m_speedY);
    double g = gravity[1];
    double energieCinetique = 0.5 * mass * v * v;
    double energiePotentielle = mass * g * -player->m_posY;
    double energieTotale = energieCinetique + energiePotentielle;

    if (fontLoaded) {
        sf::Text textVitesse(font);
        textVitesse.setCharacterSize(18);
        textVitesse.setFillColor(sf::Color::Red);
        textVitesse.setPosition(sf::Vector2f(10.f, 10.f));
        textVitesse.setString("Speed : " + std::to_string(vitesse) + " units/sec");

        sf::Text textEnergieCinetique(font);
        textEnergieCinetique.setCharacterSize(18);
        textEnergieCinetique.setFillColor(sf::Color::Red);
        textEnergieCinetique.setPosition(sf::Vector2f(10.f, 30.f));
        textEnergieCinetique.setString("Energie Cinetique : " + std::to_string(energieCinetique) + " J");

        sf::Text textEnergiePotentielle(font);
        textEnergiePotentielle.setCharacterSize(18);
        textEnergiePotentielle.setFillColor(sf::Color::Red);
        textEnergiePotentielle.setPosition(sf::Vector2f(10.f, 50.f));
        textEnergiePotentielle.setString("Energie Potentielle : " + std::to_string(energiePotentielle) + " J");

        sf::Text textEnergieTotale(font);
        textEnergieTotale.setCharacterSize(18);
        textEnergieTotale.setFillColor(sf::Color::Red);
        textEnergieTotale.setPosition(sf::Vector2f(10.f, 70.f));
        textEnergieTotale.setString("Energie Totale : " + std::to_string(energieTotale) + " J");

        _window.draw(textVitesse);
        _window.draw(textEnergieCinetique);
        _window.draw(textEnergiePotentielle);
        _window.draw(textEnergieTotale);
    }
    else {
        std::cout << "Speed : " << vitesse << " units/sec" << std::endl;
        std::cout << "Energie Cinetique : " << energieCinetique << " MJ" << std::endl;
        std::cout << "Energie Potentielle : " << energiePotentielle << " MJ" << std::endl;
        std::cout << "Energie Totale : " << energieTotale << " MJ" << std::endl;
    } // Print in console if font is not loaded
}

void GameWindow::show(int width, int height, const std::string& title)
{
    _window.create(sf::VideoMode(sf::Vector2u(width, height)), title);

    screen_res = _window.getSize();

    while (_window.isOpen())
    {
        current_dt = compute_delta_t();
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

    // Draw background
    if (backgroundSprite) {
        backgroundSprite->setScale(sf::Vector2f(screen_res.x / backgroundSprite->getLocalBounds().size.x,
            screen_res.y / backgroundSprite->getLocalBounds().size.y));
        _window.draw(*backgroundSprite);
    }
#ifdef SFML_DEBUG // if in debug, prints the axis
    render_debug();
#endif
    // Draw player
    int radius = 10;

    //zoom factor
    double z = 1.0; // Adjust this value to change the zoom level
    //player position in screen coordinates
    WorldPoint playerPosition = { player->m_posX, player->m_posY };

    // Convert player position to screen coordinates
    ScreenPoint playerScreenPosition = toScreen(playerPosition, screen_res.x, screen_res.y, zoom_factor);


    if (player->m_sprite)
    {

        // to adjust according to the base rotation we want (90 = UP)
        constexpr float ROTATION_OFFSET = 90.f;

        player->m_sprite->setRotation(sf::degrees(player->m_angle + ROTATION_OFFSET));

        player->m_sprite->setPosition(sf::Vector2f(playerScreenPosition.first, playerScreenPosition.second));

        _window.draw(*player->m_sprite);
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
	playerbeforeX = player->m_posX;
    playerbeforeY = player->m_posY;

    //Ff,x​= −kvvx ; Ff,y​= −kvvy
    player->compute_speed();
    // double friction = compute_friction(player_speed);
    double frictionX = -(coef_frottements * player->m_speed * player->m_speedX * masse_volumique_atmo)/2;
    double frictionY = -(coef_frottements * player->m_speed * player->m_speedY * masse_volumique_atmo)/2;

    // if a key is pressed, we add propulsion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        player->m_speedX -= (propulsion/mass) * current_dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        player->m_speedX += (propulsion/mass) * current_dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        player->m_speedY -= (propulsion/mass) * current_dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        player->m_speedY += (propulsion/mass) * current_dt;
    }

    // whether or not a key is pressed, we compute new speed without propulsion
    player->m_speedX += ((get_forcesX() + frictionX)/ mass) * current_dt;
    player->m_speedY += ((get_forcesY() + frictionY)/ mass) * current_dt;

    player->m_posX += player->m_speedX * current_dt;
    player->m_posY += player->m_speedY * current_dt;

    compute_border_collision();

    // used by render() to rotate the sprite
    double deltaX = player->m_posX - playerbeforeX;
    double deltaY = player->m_posY - playerbeforeY;
    double moveDistance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    const double MOVE_THRESHOLD = 0.001;

    if (moveDistance > MOVE_THRESHOLD)
    {
        constexpr double PI = 3.14159265358979323846;
        player->m_angle = static_cast<float>(std::atan2(deltaY, deltaX) * 180.0 / PI);
    }
}
