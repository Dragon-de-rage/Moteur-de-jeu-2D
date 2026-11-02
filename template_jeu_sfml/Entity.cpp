#include "Entity.h"

void Entity::setTexture()
{
    if (m_texture.loadFromFile(m_textureFile)) {
        m_sprite.emplace(m_texture);
        // Centrer l'origine en utilisant getLocalBounds()
		m_sprite->setScale(sf::Vector2f(0.1f, 0.1f)); // Ajustez le facteur d'échelle selon vos besoins)
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