#pragma once

#include "Window.h"

namespace clsn
{
	bool circlesColliding(sf::CircleShape, sf::CircleShape);
	bool lineAndCircleColliding(sf::VertexArray, sf::CircleShape);
	bool lineAndCircleColliding(sf::CircleShape, sf::VertexArray);
};
