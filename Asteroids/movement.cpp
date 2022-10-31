#include "movement.h"

namespace mvmt
{
	bool loopPos(sf::Vector2f windowDims, sf::Vector2f& pos)
	{
		bool changed = false;

		// Horizontal position
		if (pos.x < 0.f)
		{
			pos.x += windowDims.x;
			return true;
		}
		else if (pos.x > windowDims.x)
		{
			pos.x -= windowDims.x;
			return true;
		}

		// Vertical position
		if (pos.y < 0.f)
		{
			pos.y += windowDims.y;
			return true;
		}
		else if (pos.y > windowDims.y)
		{
			pos.y -= windowDims.y;
			return true;
		}

		return false;
	}

	// Random velocity
	void setRandomVelocity(sf::Vector2f& velocity, sf::Vector2f minMaxSpeed, float& directionDegrees)
	{
		float minSpeed = std::min(minMaxSpeed.x, minMaxSpeed.y);
		float maxSpeed = std::max(minMaxSpeed.x, minMaxSpeed.y);

		setRandomRotation(directionDegrees);

		float newVelocity = minSpeed + (maxSpeed - minSpeed) * static_cast<float>(rand() % 1000) / 1000.f;

		float sinFactor = sinf(PI * directionDegrees / 180.f);
		float cosFactor = cosf(PI * directionDegrees / 180.f);

		velocity = sf::Vector2f(newVelocity * sinFactor, newVelocity * cosFactor);
	}

	void setRandomVelocity(sf::Vector2f& velocity, sf::Vector2f minMaxSpeed)
	{
		float directionDegreesTemp = 0.f;
		setRandomVelocity(velocity, minMaxSpeed, directionDegreesTemp);
	}

	void setRandomVelocity(sf::Vector2f& velocity, float speed, float& rotationDegrees)
	{
		setRandomVelocity(velocity, sf::Vector2f(speed, speed), rotationDegrees);
	}

	void setRandomVelocity(sf::Vector2f& velocity, float speed)
	{
		float rotationDegreesTemp = 0.f;
		setRandomVelocity(velocity, sf::Vector2f(speed, speed), rotationDegreesTemp);
	}

	// Random rotation
	void setRandomRotation(float& rotationDegrees, float& rotationSpeedDegrees, sf::Vector2f minMaxRotationSpeedDegrees)
	{
		setRandomRotation(rotationDegrees);
		
		float minRotSpeedDegrees = std::min(minMaxRotationSpeedDegrees.x, minMaxRotationSpeedDegrees.y);
		float maxRotSpeedDegrees = std::max(minMaxRotationSpeedDegrees.x, minMaxRotationSpeedDegrees.y);

		// Setting random rotation speed
		float randomFactor = static_cast<float>(rand() % 1000) / 1000.f;
		float randomSign = -1 + static_cast<float>(rand() % 2) * 2;
		rotationSpeedDegrees = minRotSpeedDegrees + (maxRotSpeedDegrees - minRotSpeedDegrees) * randomFactor;
		rotationSpeedDegrees *= randomSign;
	}

	void setRandomRotation(float& rotationDegrees)
	{
		rotationDegrees = static_cast<float>(rand() % 360);
	}
}
