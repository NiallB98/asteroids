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
	
	float rotationSpeedDegrees = 0.f;
	
	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	float minSpeed = 1.f;
	float maxSpeed = 4.f;
	void setRandomVelocity();

	void updatePos();

public:
	Asteroid();
	~Asteroid();

	bool isAlive();

	// Movement
	void setPos(sf::Vector2f);

	// Update
	void update();

	void draw(Window&);
};
