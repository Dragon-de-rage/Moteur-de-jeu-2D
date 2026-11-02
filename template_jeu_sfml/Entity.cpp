#include "Entity.h"

void Entity::draw(std::pair<int, int> screenPoint, sf::RenderWindow* window)
{
    if (m_sprite)
    {
        // to adjust according to the base rotation we want (90 = UP)
        constexpr float ROTATION_OFFSET = 90.f;

        m_sprite->setRotation(sf::degrees(m_angle + ROTATION_OFFSET));

        m_sprite->setPosition(sf::Vector2f(screenPoint.first, screenPoint.second));

        window->draw(*m_sprite);
    }
    else
    {
        //create player circle shape
        sf::CircleShape circle(radius);

        circle.setFillColor(sf::Color::Yellow);

        circle.setPosition(sf::Vector2f(screenPoint.first - radius, screenPoint.second - radius));

        window->draw(circle);
    }
}

void Entity::setTexture(sf::Vector2f scale)
{
    if (m_texture.loadFromFile(m_textureFile)) {
        m_sprite.emplace(m_texture);
        // Centrer l'origine en utilisant getLocalBounds()
        m_sprite->setScale(scale); // Ajustez le facteur d'échelle selon vos besoins)
        auto bounds = m_sprite->getLocalBounds();
        m_sprite->setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    }
}

double Entity::get_pos_X()
{
    return m_posX;
}

double Entity::get_pos_Y()
{
    return m_posY;
}

double Entity::get_angle()
{
    return m_angle;
}