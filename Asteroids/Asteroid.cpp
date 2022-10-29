#include "Asteroid.h"

Asteroid::Asteroid()
{
	initCollider();
	initShape();
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
