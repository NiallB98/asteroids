#pragma once

#include "Window.h"

class Asteroid
{
private:
	int size = 3;

	void hit(int&);

	// Shapes
	bool doDrawCollider = true;
	sf::CircleShape collider;
	void initCollider();

	// Shape
	void initShape();

	// Drawing
	void drawCollider(Window&);
	void drawShape(Window&);

	// Movement
	sf::Vector2f pos = sf::Vector2f(0.f, 0.f);
	float speed = 0.f;
	float maxSpeed = 5.f;
	float dirDegrees = 0.f;
	float rotationSpeedCWDegrees = 0.f;
	void rotate();

public:
	Asteroid();
	~Asteroid();

	bool isAlive();

	// Movement
	void setPos(sf::Vector2f);
	void setRandomVelocity();
	void move();

	void draw(Window&);
};
