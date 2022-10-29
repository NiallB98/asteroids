#include "Asteroid.h"

Asteroid::Asteroid()
{
	initCollider();
	initShape();
	setRandomVelocity();
}

Asteroid::~Asteroid()
{

}

void Asteroid::hit(int& score)
{
	score++;
	size--;
}

// Initisalising the collider and shape
void Asteroid::initCollider()
{
	collider = sf::CircleShape(50, 8);
	collider.setPosition(sf::Vector2f(100.f, 200.f));
	collider.setFillColor(sf::Color::Red);
}

void Asteroid::initShape()
{

}

bool Asteroid::isAlive()
{
	return size > 0;
}

// Drawing
void Asteroid::drawCollider(Window& window)
{
	if (doDrawCollider)
		window.draw(collider);
}

void Asteroid::drawShape(Window& window)
{

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
}

void Asteroid::setRandomVelocity()
{
	float rotationDegrees = static_cast<float>(rand() % 360);

	float newSpeed = minSpeed + (maxSpeed - minSpeed) * static_cast<float>(rand() % 1000) / 1000.f;

	float sinFactor = sinf(PI * rotationDegrees / 180.f);
	float cosFactor = cosf(PI * rotationDegrees / 180.f);

	speed = sf::Vector2f(newSpeed * sinFactor, newSpeed * cosFactor);
}

// Updates
void Asteroid::updatePos()
{
	setPos(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));
}

void Asteroid::update()
{
	updatePos();
}
