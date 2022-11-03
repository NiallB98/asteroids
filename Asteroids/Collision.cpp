#include "collision.h"

namespace clsn
{
	bool circlesColliding(sf::CircleShape circle1, sf::CircleShape circle2)
	{
		sf::Vector2f pos1 = circle1.getPosition();
		sf::Vector2f pos2 = circle2.getPosition();

		return circle1.getRadius() + circle2.getRadius() >
			std::sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));
	}

	bool lineAndCircleColliding(sf::VertexArray line, sf::CircleShape circle)
	{
		float distanceFromCircleCentre = std::sqrtf(
			(line[0].position.x - circle.getPosition().x) * (line[0].position.x - circle.getPosition().x) +
			(line[0].position.y - circle.getPosition().y) * (line[0].position.y - circle.getPosition().y));

		float radius = std::floor(circle.getRadius());

		if (distanceFromCircleCentre < radius)
			return true;

		distanceFromCircleCentre = std::sqrtf(
			(line[1].position.x - circle.getPosition().x) * (line[1].position.x - circle.getPosition().x) +
			(line[1].position.y - circle.getPosition().y) * (line[1].position.y - circle.getPosition().y));

		if (distanceFromCircleCentre < radius)
			return true;
		else
			return false;
	}

	bool lineAndCircleColliding(sf::CircleShape circle, sf::VertexArray line)
	{
		return lineAndCircleColliding(line, circle);
	}
}
