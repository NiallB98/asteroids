#pragma once

#include "Window.h"
#include "Projectile.h"
#include "Score.h"

class Asteroid
{
private:
	int size = 2;
	float maxRadiusFactor = 18;
	float minRadiusFactor = 9;
	float getRadius();
	float getRadius(int);

	void hit(Score&);

	// Shape
	int vertices = 8 + 1;
	sf::Color vertexColour = sf::Color::White;
	sf::VertexArray shape;
	void initShape();
	void initVertexArray();
	void updateVertexArray();
	std::vector<float> vertexRadius = std::vector<float>(vertices);

	// Collider
	bool doDrawCollider = true;
	sf::CircleShape collider;
	void initCollider();

	// Drawing
	void drawCollider(Window&);
	void drawShape(Window&);

	// Movement
	sf::Vector2f pos = sf::Vector2f(0.f, 0.f);
	
	float rotationSpeedDegrees = 0.f;
	sf::Vector2f minMaxRotationSpeedDegrees = sf::Vector2f(0.5f, 3.f);
	float rotationDegrees = 0.f;
	void rotate();
	
	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	sf::Vector2f minMaxSpeed = sf::Vector2f(1.f, 3.f);

	void updatePos(sf::Vector2f);

	// Collsion checking
	bool collisionWithAsteroids(std::vector<Projectile>&);
	bool collisionChecks(std::vector<Projectile>&);

public:
	Asteroid();
	~Asteroid();

	bool isAlive();
	sf::CircleShape getCollider();

	// Movement
	void setPos(sf::Vector2f);

	// Update
	void update(sf::Vector2f);

	void draw(Window&);
};
