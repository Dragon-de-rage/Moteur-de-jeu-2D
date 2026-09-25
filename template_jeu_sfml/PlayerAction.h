#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>

enum class PlayerAction
{
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	ActionPrimary
};

using KeyBinding = std::unordered_map<PlayerAction, sf::Keyboard::Key>;