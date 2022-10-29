#include "Player.h"

Player::Player()
{
	initCollider();
	initShape();
}

Player::~Player()
{

}

// Initialising the collider and shape
void Player::initCollider()
{
	collider = sf::CircleShape(25, 3);
	collider.setPosition(sf::Vector2f(300.f, 300.f));
	collider.setFillColor(sf::Color::Green);
}

void Player::updateVertexArray()
{
	float topLength = 15.f;
	float sideXLength = 10.f;
	float sideYLength = 12.f;

	float sinFactor = sinf(PI * rotationDegrees / 180.f);
	float cosFactor = cosf(PI * rotationDegrees / 180.f);

	float topRelX = topLength * sinFactor;
	float topRelY = -topLength * cosFactor;

	float rSideRelX = sideXLength * cosFactor - sideYLength * sinFactor;
	float rSideRelY = sideYLength * cosFactor + sideXLength * sinFactor;

	float lSideRelX = -sideXLength * cosFactor - sideYLength * sinFactor;
	float lSideRelY = sideYLength * cosFactor + -sideXLength * sinFactor;
	
	shape[0].position = sf::Vector2f(pos.x + topRelX, pos.y + topRelY);
	shape[1].position = sf::Vector2f(pos.x + rSideRelX, pos.y + rSideRelY);
	shape[2].position = sf::Vector2f(pos.x + lSideRelX, pos.y + lSideRelY);
	shape[3].position = shape[0].position;
}

void Player::initShape()
{
	shape = sf::VertexArray(sf::LinesStrip, 4);

	// Defining the position of the shape's points
	updateVertexArray();

	// Defining the colour of the shape
	shape[0].color = sf::Color::Green;
	shape[1].color = sf::Color::Blue;
	shape[2].color = sf::Color::Red;
	shape[3].color = shape[0].color;
}

// Drawing
void Player::drawCollider(Window& window)
{
	if (doDrawCollider)
		window.draw(collider);
}

void Player::drawShape(Window& window)
{
	window.draw(shape);
}

void Player::draw(Window& window)
{
	drawCollider(window);
	drawShape(window);
}

// Movement
void Player::setPos(sf::Vector2f newPos)
{
	pos = newPos;
	collider.setPosition(newPos);

	updateVertexArray();
}

void Player::rotate(bool dir)
{
	rotationDegrees += rotationSpeed * (dir ? 1.f : -1.f);
	if (rotationDegrees < 0.f)
		rotationDegrees += 360.f;

	updateVertexArray();
}

// Update
void Player::update()
{

}
