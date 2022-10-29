#pragma once

#include "Window.h"

class Player
{
private:
	// Collider
	bool doDrawCollider = false;
	sf::CircleShape collider;
	void initCollider();

	// Shape
	sf::VertexArray shape;
	void initShape();
	void updateVertexArray();

	// Drawing
	void drawCollider(Window&);
	void drawShape(Window&);

	// Movement
	sf::Vector2f pos = sf::Vector2f(0.f, 0.f);
	float rotationDegrees = 0.f;
	float rotationSpeed = 4.f;

public:
	Player();
	~Player();

	// Movement
	void setPos(sf::Vector2f);
	void rotate(bool);

	// Update
	void update();

	void draw(Window&);
};

