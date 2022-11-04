#include "Asteroid.h"

#include "Projectile.h"
#include "Score.h"

Asteroid::Asteroid()
{
	initShape();
	mvmt::setRandomVelocity(speed, minMaxSpeed);
	mvmt::setRandomRotation(rotationDegrees, rotationSpeedDegrees, minMaxRotationSpeedDegrees);
}

Asteroid::Asteroid(sf::Vector2f newPos)
{
	initShape();
	mvmt::setRandomVelocity(speed, minMaxSpeed);
	mvmt::setRandomRotation(rotationDegrees, rotationSpeedDegrees, minMaxRotationSpeedDegrees);

	setPos(newPos);
}

Asteroid::Asteroid(sf::Vector2f newPos, int newSize)
{
	size = newSize;
	
	initShape();
	mvmt::setRandomVelocity(speed, minMaxSpeed);
	mvmt::setRandomRotation(rotationDegrees, rotationSpeedDegrees, minMaxRotationSpeedDegrees);

	setPos(newPos);
}

Asteroid::~Asteroid()
{

}

int Asteroid::getSize()
{
	return size;
}

float Asteroid::getRadius()
{
	float maxRadius = 0.f;
	for (int i = 0; i < vertices; i++)
		if (maxRadius < getRadius(i))
			maxRadius = getRadius(i);
	
	return maxRadius;
}

float Asteroid::getRadius(int i)
{
	return static_cast<float>(size) * vertexRadius[i];
}

void Asteroid::hit(Score& score)
{
	score.asteroidHit(size);
	size--;

	updateVertexArray();
	resetCollider();
}

// Initisalising the shape and collider
void Asteroid::updateVertexArray()
{
	for (int i = 0; i < vertices - 1; i++)
	{
		float angleDegrees = rotationDegrees + i * 360.f / vertices;

		float sinFactor = sinf(PI * angleDegrees / 180.f);
		float cosFactor = cosf(PI * angleDegrees / 180.f);

		shape[i].position = sf::Vector2f(pos.x + getRadius(i) * sinFactor, pos.y + getRadius(i) * cosFactor);
	}

	shape[vertices-1].position = shape[0].position;
}

void Asteroid::initVertexArray()
{
	for (int i = 0; i < vertices; i++)
	{
		if (i == vertices - 1)
		{
			vertexRadius[i] = vertexRadius[0];
		}
		else
		{
			vertexRadius[i] = minRadiusFactor +
				static_cast<float>(rand() % static_cast<int>(maxRadiusFactor - minRadiusFactor));
		}

		// Defining the colour of the shape
		shape[i].color = vertexColour;
	}
	
	// Defining the position of the shape's points
	updateVertexArray();
}

void Asteroid::initShape()
{
	shape = sf::VertexArray(sf::LinesStrip, vertices);

	initVertexArray();
	initCollider();
}

sf::CircleShape Asteroid::getCollider()
{
	return collider;
}

void Asteroid::initCollider()
{
	collider = sf::CircleShape(getRadius());
	collider.setOrigin(sf::Vector2f(getRadius(), getRadius()));
	collider.setPosition(sf::Vector2f(pos));
	collider.setFillColor(sf::Color::Red);
}

void Asteroid::resetCollider()
{
	collider.setRadius(getRadius());
	collider.setOrigin(sf::Vector2f(getRadius(), getRadius()));
	collider.setPosition(sf::Vector2f(pos));
	collider.setFillColor(sf::Color::Red);
}

bool Asteroid::isAlive()
{
	return size > 0;
}

bool Asteroid::doSplit()
{
	return splitting;
}

// Drawing
void Asteroid::drawCollider(Window& window)
{
	if (doDrawCollider)
		window.draw(collider);
}

void Asteroid::drawShape(Window& window)
{
	window.draw(shape);
}

void Asteroid::draw(Window& window)
{
	drawCollider(window);
	drawShape(window);
}

// Movement
void Asteroid::setPos(sf::Vector2f newPos)
{
	pos = newPos;
	collider.setPosition(newPos);

	updateVertexArray();
}

sf::Vector2f Asteroid::getPos()
{
	return pos;
}

void Asteroid::rotate()
{
	rotationDegrees += rotationSpeedDegrees;

	updateVertexArray();
}

// Updates
void Asteroid::updatePos(sf::Vector2f windowDims)
{
	setPos(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));

	if (mvmt::loopPos(windowDims, pos))
		setPos(pos);
}

// Collsion checking
bool Asteroid::collisionWithProjectiles(std::vector<Projectile>& playerProjectiles)
{
	for (int i = 0; i < playerProjectiles.size(); i++)
	{
		if (clsn::lineAndCircleColliding(collider, playerProjectiles[i].getCollider()))
		{
			hasBeenHit = true;
			return true;
		}
	}
	return false;
}

bool Asteroid::collisionChecks(std::vector<Projectile>& playerProjectiles)
{
	return collisionWithProjectiles(playerProjectiles);
}

void Asteroid::update(sf::Vector2f windowDims, std::vector<Projectile>& playerProjectiles)
{
	updatePos(windowDims);
	rotate();
	if (isAlive())
		collisionChecks(playerProjectiles);
}

void Asteroid::split()
{
	splitting = true;
}

void Asteroid::clearSplit()
{
	splitting = false;
}

void Asteroid::reduce(Score& score)
{
	mvmt::setRandomVelocity(speed, minMaxSpeed);
	mvmt::setRandomRotation(rotationDegrees, rotationSpeedDegrees, minMaxRotationSpeedDegrees);

	firstFrame = true;
	
	hit(score);
	split();
}

void Asteroid::die(Score& score)
{
	hit(score);
}

void Asteroid::postUpdate(Score& score)
{
	if (hasBeenHit and not firstFrame)
	{
		if (size > 1)
			reduce(score);
		else
			die(score);
		hasBeenHit = false;
	}
	else if (firstFrame)
		firstFrame = false;
}
