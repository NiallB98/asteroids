#pragma once

#include "Window.h"

namespace mvmt
{
	bool loopPos(sf::Vector2f, sf::Vector2f&);

	void setRandomVelocity(sf::Vector2f&, sf::Vector2f, float&);
	void setRandomVelocity(sf::Vector2f&, sf::Vector2f);
	void setRandomVelocity(sf::Vector2f&, float, float&);
	void setRandomVelocity(sf::Vector2f&, float);

	void setRandomRotation(float&, float&, sf::Vector2f);
	void setRandomRotation(float&);
};
