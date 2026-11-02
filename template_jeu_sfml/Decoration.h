#pragma once

#include "Entity.h"
#include <string>

class Decoration : public Entity
{
public:
	struct Config
	{
		std::string textureFile;
		sf::Vector2f start;
		sf::Vector2f end;

		float speed = 100.0f;
		float scale = 1.0f;

		bool flipWithDirection = true;
		bool facesLeft = false;

		float hopHeight = 0.0f;
		float hopFrequency = 0.0f;

		float flapAmplitude = 0.0f;
		float flapFrequency = 0.0f;
	};

	explicit Decoration(const Config& config);

	void update(float deltaTime) override;

	void draw(sf::RenderTarget& target) const;

private : 
	Config m_cfg;
	float m_length = 0.0f;
	float m_distance = 0.0f;

	int m_dir = 1;
	float m_time = 0.0f;
};