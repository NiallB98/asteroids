#include "Projectile.h"
#include "Asteroid.h"

Projectile::Projectile()
{
	initShape();
	mvmt::setRandomVelocity(speed, maxSpeed, rotationDegrees);
}

Projectile::Projectile(sf::Vector2f newPos, float newRotationDegrees, sf::Clock& clock)
{
	initShape();
	rotationDegrees = newRotationDegrees;

	float sinFactor = sinf(PI * rotationDegrees / 180.f);
	float cosFactor = cosf(PI * rotationDegrees / 180.f);

	speed = sf::Vector2f(maxSpeed * sinFactor, -maxSpeed * cosFactor);
	setPos(newPos);

	createdAtSeconds = clock.getElapsedTime().asSeconds();
}

Projectile::~Projectile()
{

}

bool Projectile::isAlive()
{
	return alive;
}

sf::VertexArray Projectile::getCollider()
{
	return shape;
}

bool Projectile::hasExpired(sf::Clock& clock)
{
	return createdAtSeconds + lifespanSeconds < clock.getElapsedTime().asSeconds();
}

void Projectile::initShape()
{
	shape = sf::VertexArray(sf::LinesStrip, vertices);

	initVertexArray();
}

void Projectile::initVertexArray()
{
	for (int i = 0; i < vertices; i++)
	{
		if (i == vertices - 1)
		{
			vertexRelPos[i] = vertexRelPos[0];
		}

		// Defining the colour of the shape
		shape[i].color = vertexColour;
	}

	updateVertexArray();
}

void Projectile::updateVertexArray()
{
	float sinFactor = sinf(PI * rotationDegrees / 180.f);
	float cosFactor = cosf(PI * rotationDegrees / 180.f);

	float topRelX = size * sinFactor;
	float topRelY = -size * cosFactor;

	shape[0].position = sf::Vector2f(pos.x + topRelX, pos.y + topRelY);
	shape[1].position = sf::Vector2f(pos.x - topRelX, pos.y - topRelY);
}

// Movement
void Projectile::setPos(sf::Vector2f newPos)
{
	pos = newPos;

	updateVertexArray();
}

void Projectile::move()
{
	setPos(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));
}

void Projectile::updatePos(sf::Vector2f windowDims)
{
	move();
	if (mvmt::loopPos(windowDims, pos))
		setPos(pos);
}

// Collsion checking
bool Projectile::collisionWithAsteroids(std::vector<Asteroid>& asteroids)
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (clsn::lineAndCircleColliding(asteroids[i].getCollider(), shape))
		{
			hasBeenHit = true;
			return true;
		}
	}
	return false;
}

bool Projectile::collisionChecks(std::vector<Asteroid>& asteroids)
{
	return collisionWithAsteroids(asteroids);
}

void Projectile::update(sf::Vector2f windowDims, std::vector<Asteroid>& asteroids)
{
	// The projectile checks collisions first so that objects colliding with the projectile
	// do not need to account for its speed
	collisionChecks(asteroids);
	updatePos(windowDims);
}

void Projectile::die()
{
	alive = false;
}

void Projectile::postUpdate()
{
	if (hasBeenHit)
		die();
}

void Projectile::draw(Window& window)
{
	window.draw(shape);
}
