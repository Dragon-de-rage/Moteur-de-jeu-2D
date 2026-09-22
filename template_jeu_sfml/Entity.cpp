#include "Entity.h"

void Entity::setTexture(const std::string& textureFile)
{
    if (m_texture.loadFromFile(textureFile)) {
        m_sprite.emplace(m_texture);
        // Centrer l'origine en utilisant getLocalBounds()
        auto bounds = m_sprite->getLocalBounds();
        m_sprite->setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));
    }
}
