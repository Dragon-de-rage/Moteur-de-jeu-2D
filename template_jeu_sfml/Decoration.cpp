#include "Decoration.h"

#include<cmath>
#include <iostream>

namespace { constexpr float PI = 3.14159265358979323846f; }

Decoration::Decoration(const Config& config)
	: m_cfg(config)
{
	m_textureFile = m_cfg.textureFile;

	if (m_texture.loadFromFile(m_textureFile))
	{
		m_sprite.emplace(m_texture);
		auto bounds = m_sprite->getLocalBounds();
		m_sprite->setOrigin({ bounds.size.x / 2.0f, bounds.size.y / 2.0f });
	}
	else
	{
		std::cout << "Failed to load texture: " << m_textureFile << std::endl;
	}

	sf::Vector2f d = m_cfg.end - m_cfg.start;

	m_length = std::sqrt(d.x * d.x + d.y * d.y);

	update(0.0f); // place the sprite at the start position
}

void Decoration::update(float dt)
{
	if (!m_sprite || m_length <= 0.0f)
		return;

	m_time += dt;

	// go and back along the path

	m_distance += m_dir * m_cfg.speed * dt;
	if (m_distance >= m_length)
	{
		m_distance = m_length;
		m_dir = -1;
	}
	else if (m_distance < 0.0f)
	{
		m_distance = 0.0f;
		m_dir = 1;
	}

	float t = m_distance / m_length;

	sf::Vector2f pos = m_cfg.start + t * (m_cfg.end - m_cfg.start);

	// for the hop of the decoration
	if (m_cfg.hopHeight > 0.f)
	{
		pos.y -= m_cfg.hopHeight * std::abs(std::sin(PI * m_cfg.hopFrequency * m_time));
	}

	// flip the sprite if needed
	float flip = 1.0f;
	if (m_cfg.flipWithDirection)
		flip = ((m_dir > 0) == m_cfg.facesLeft) ? -1.f : 1.f;

	// for the flap of the wings 
	float flap = 1.f;
	if (m_cfg.flapAmplitude > 0.f)
		flap = 1.f - m_cfg.flapAmplitude * (0.5f + 0.5f * std::sin(2.f * PI * m_cfg.flapFrequency * m_time));

	m_sprite->setPosition(pos);
	m_sprite->setScale({ flip * m_cfg.scale * flap, m_cfg.scale });
}

void Decoration::draw(sf::RenderTarget& target) const
{
	if (m_sprite)
		target.draw(*m_sprite);
}