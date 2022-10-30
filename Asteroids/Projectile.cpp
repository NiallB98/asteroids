#include "Projectile.h"

Projectile::Projectile()
{
	initShape();
	setRandomSpeed();
}

Projectile::~Projectile()
{

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
	float topRelY = size * cosFactor;

	shape[0].position = sf::Vector2f(pos.x + topRelX, pos.y + topRelY);
	shape[1].position = sf::Vector2f(pos.x - topRelX, pos.y - topRelY);
}

// Movement
void Projectile::setRandomSpeed()
{
	rotationDegrees = static_cast<float>(rand() % 360);

	float sinFactor = sinf(PI * rotationDegrees / 180.f);
	float cosFactor = cosf(PI * rotationDegrees / 180.f);

	speed = sf::Vector2f(maxSpeed * sinFactor, maxSpeed * cosFactor);
}

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
	loopPos(windowDims);
}

void Projectile::loopPos(sf::Vector2f windowDims)
{
	bool changed = false;

	// Horizontal position
	if (pos.x < 0.f)
	{
		pos.x += windowDims.x;
		changed = true;
	}
	else if (pos.x > windowDims.x)
	{
		pos.x -= windowDims.x;
		changed = true;
	}

	// Vertical position
	if (pos.y < 0.f)
	{
		pos.y += windowDims.y;
		changed = true;
	}
	else if (pos.y > windowDims.y)
	{
		pos.y -= windowDims.y;
		changed = true;
	}

	if (changed)
		setPos(sf::Vector2f(pos.x, pos.y));
}

void Projectile::update(sf::Vector2f windowDims)
{
	updatePos(windowDims);
}

void Projectile::draw(Window& window)
{
	window.draw(shape);
}
