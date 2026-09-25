#include "Player.h"

Player::Player(double x, double y)
	: m_posX(x), m_posY(y), m_angle(0.0), m_speedX(0.0), m_speedY(0.0)
{
	m_textureFile = "Images/animal_linux_penguin_2598.png";
	setTexture();
}

void Player::update(float deltaTime)
{
    m_posX += m_speedX * deltaTime;
    m_posY += m_speedY * deltaTime;

	if (m_sprite)
	{
		m_sprite->setPosition(sf::Vector2f(m_posX, m_posY));
		m_sprite->setRotation(sf::Angle(sf::radians(m_angle)));
	}
}

void Player::compute_speed() {
    m_speed = std::sqrt(m_speedX*m_speedX + m_speedY*m_speedY);
}

void Player::compute_movement(double& coef_frottements, double& masse_volumique_atmo, double& current_dt, const double& forces_X,
                              const double& forces_Y, double& zoom_factor, const sf::Vector2u& screen_res)
{
    player_before_X = m_posX;
    player_before_Y = m_posY;

    //Ff,x​= −kvvx ; Ff,y​= −kvvy
    compute_speed();
    // double friction = compute_friction(player_speed);
    double frictionX = -(coef_frottements * m_speed * m_speedX * masse_volumique_atmo)/2;
    double frictionY = -(coef_frottements * m_speed * m_speedY * masse_volumique_atmo)/2;

    // if a key is pressed, we add propulsion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        m_speedX -= (propulsion/mass) * current_dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        m_speedX += (propulsion/mass) * current_dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        m_speedY -= (propulsion/mass) * current_dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        m_speedY += (propulsion/mass) * current_dt;
    }

    // whether or not a key is pressed, we compute new speed without propulsion
    m_speedX += ((forces_X + frictionX)/ mass) * current_dt;
    m_speedY += ((forces_Y + frictionY)/ mass) * current_dt;

    m_posX += m_speedX * current_dt;
    m_posY += m_speedY * current_dt;

    compute_border_collision(screen_res, zoom_factor, current_dt);

    double deltaX = m_posX - player_before_X;
    double deltaY = m_posY - player_before_Y;
    double moveDistance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    const double MOVE_THRESHOLD = 0.001;

    if (moveDistance > MOVE_THRESHOLD)
    {
        constexpr double PI = 3.14159265358979323846;
        m_angle = static_cast<float>(std::atan2(deltaY, deltaX) * 180.0 / PI);
    }
}

void Player::compute_border_collision(const sf::Vector2u& screen_res, double zoom_factor, double current_dt)
{
    //calculate the limits of the player's position based on the screen size and zoom factor
    double xMax = (screen_res.x / 2.0) / zoom_factor - radius;
    double xMin = -xMax;

    double yMax = (screen_res.y / 2.0) / zoom_factor - radius;
    double yMin = -yMax;

    //check if the player is out of bounds and adjust position and speed accordingly
    if (m_posX > xMax) {
        double oldX = m_posX - m_speedX * current_dt;
        double timeToCollision = (xMax - oldX) / m_speedX;
        double remainingTime = current_dt - timeToCollision;

        m_speedX = -m_speedX;

        m_posX = xMax + (m_speedX * remainingTime);
    }
    else if (m_posX < xMin) {
        double oldX = m_posX - m_speedX * current_dt;
        double timeToCollision = (xMin - oldX) / m_speedX;
        double remainingTime = current_dt - timeToCollision;

        m_speedX = -m_speedX;

        m_posX = xMin + (m_speedX * remainingTime);
    }

    if (m_posY > yMax) {
        double oldY = m_posY - m_speedY * current_dt;
        double timeToCollision = (yMax - oldY) / m_speedY;
        double remainingTime = current_dt - timeToCollision;

        m_speedY = -m_speedY;

        m_posY= m_posY + (m_speedY * remainingTime);
    }
    else if (m_posY < yMin) {
        double oldY = m_posY - m_speedY * current_dt;
        double timeToCollision = (yMin - oldY) / m_speedY;
        double remainingTime = current_dt - timeToCollision;

        m_speedY = -m_speedY;

        m_posY = m_posY + (m_speedY * remainingTime);
    }
}

double Player::get_pos_X()
{
    return m_posX;
}

double Player::get_pos_Y()
{
    return m_posY;
}

double Player::get_player_before_X()
{
    return player_before_X;
}

double Player::get_player_before_Y()
{
    return player_before_Y;
}

// double Player::get_speed_X()
// {
//     return m_speedX;
// }

// double Player::get_speed_Y()
// {
//     return m_speedY;
// }

double Player::compute_and_get_speed()
{
    compute_speed();
    return m_speed;
}

void Player::setKeyBinding(const KeyBinding& binding)
{
	m_keyBinding = binding;
}

void Player::setKey(PlayerAction action, sf::Keyboard::Key key)
{	
	m_keyBinding[action] = key;
}

bool Player::isKeyPressed(PlayerAction action)
{
	if (!m_keyBinding.contains(action))
		return false;
    return sf::Keyboard::isKeyPressed(m_keyBinding.at(action));
}