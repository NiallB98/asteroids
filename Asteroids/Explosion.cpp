#include "Explosion.h"

#include "Audio.h"

Explosion::Explosion()
{
	initShapes();
}

Explosion::Explosion(Audio& audio, sf::Vector2f newPos, int newSize, sf::Clock& clock)
{
	pos = newPos;
	if (newSize == 0)
		size = 1;
	else
		size = newSize;
	createdAtSeconds = clock.getElapsedTime().asSeconds();
	
	initShapes();

	audio.playExplosion(newSize);
}

Explosion::~Explosion()
{

}

void Explosion::updateVertexArrays()
{
	float sinFactor, cosFactor;
	float topRelX, topRelY;
	
	for (int i = 0; i < particles.size(); i++)
	{
		sinFactor = sinf(PI * shapeRotations[i] / 180.f);
		cosFactor = cosf(PI * shapeRotations[i] / 180.f);

		topRelX = particleSize * sinFactor;
		topRelY = -particleSize * cosFactor;

		particles[i][0].position = sf::Vector2f(shapePositions[i].x + topRelX, shapePositions[i].y + topRelY);
		particles[i][1].position = sf::Vector2f(shapePositions[i].x - topRelX, shapePositions[i].y - topRelY);
	}
}

void Explosion::setPos(sf::Vector2f newPos)
{
	pos = newPos;

	updateVertexArrays();
}

void Explosion::initShapes()
{
	for (int i = 0; i < numParticles; i++)
		shapePositions[i] = pos;
	
	initShapeVelocities();
	updateVertexArrays();
}

void Explosion::initShapeVelocities()
{
	float sinFactor, cosFactor;
	float speed, speedFactor;
	sf::Vector2f velocity;
	
	for (int i = 0; i < particles.size(); i++)
	{
		shapeRotations[i] = static_cast<float>(rand() % 360);

		sinFactor = sinf(PI * shapeRotations[i] / 180.f);
		cosFactor = cosf(PI * shapeRotations[i] / 180.f);

		speedFactor = minSpeedFactor + (maxSpeedFactor - minSpeedFactor) * static_cast<float>(rand() % 1000);
		speed = size * speedFactor;

		velocity = sf::Vector2f(speed * sinFactor, -speed * cosFactor);
		
		shapeVelocities[i] = velocity;
	}
}

void Explosion::moveShapes()
{
	for (int i = 0; i < particles.size(); i++)
		shapePositions[i] = sf::Vector2f(shapePositions[i].x + shapeVelocities[i].x,
			shapePositions[i].y + shapeVelocities[i].y);

	updateVertexArrays();
}

bool Explosion::hasExpired()
{
	return not alive;
}

void Explosion::update()
{
	moveShapes();
}

void Explosion::postUpdate(sf::Clock& clock)
{
	if (alive)
	{
		if (createdAtSeconds + lifespanSeconds < clock.getElapsedTime().asSeconds())
			alive = false;
	}
}

void Explosion::draw(Window& window)
{
	for (int i = 0; i < particles.size(); i++)
		window.draw(particles[i]);
}
