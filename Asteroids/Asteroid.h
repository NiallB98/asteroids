#pragma once

#include "Window.h"

class Asteroid
{
private:
	int size = 3;
	float maxRadiusFactor = 40;
	float minRadiusFactor = 15;
	float getRadius();

	void hit(int&);

	// Shapes
	bool doDrawCollider = false;
	sf::CircleShape collider;
	void initCollider();

	// Shape
	int vertices = 8 + 1;
	sf::Color vertexColour = sf::Color::White;
	sf::VertexArray shape;
	void initShape();
	void initVertexArray();
	void updateVertexArray();
	std::vector<float> vertexRadius = std::vector<float>(vertices);

	// Drawing
	void drawCollider(Window&);
	void drawShape(Window&);

	// Movement
	sf::Vector2f pos = sf::Vector2f(0.f, 0.f);
	
	float rotationSpeedDegrees = 0.f;
	float minRotationSpeedDegrees = 1.f;
	float maxRotationSpeedDegrees = 4.f;
	float rotationDegrees = 0.f;
	void setRandomRotation();
	void rotate();
	
	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	float minSpeed = 1.f;
	float maxSpeed = 3.f;
	void setRandomVelocity();

	void updatePos(sf::Vector2f);
	void loopPos(sf::Vector2f);

public:
	Asteroid();
	~Asteroid();

	bool isAlive();

	// Movement
	void setPos(sf::Vector2f);

	// Update
	void update(sf::Vector2f);

	void draw(Window&);
};
