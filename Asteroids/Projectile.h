#pragma once

#include "Window.h"

class Projectile
{
private:
	sf::Vector2f pos = sf::Vector2f(50.f, 50.f);

	// Shape
	float size = 4.f;
	int vertices = 2;
	sf::Color vertexColour = sf::Color::White;
	sf::VertexArray shape;
	void initShape();
	void initVertexArray();
	void updateVertexArray();
	std::vector<sf::Vector2f> vertexRelPos = std::vector<sf::Vector2f>(vertices);

	// Movement
	float rotationDegrees = 45.f;

	void move();
	void setPos(sf::Vector2f);
	void updatePos(sf::Vector2f);

	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	float maxSpeed = 8.f;

	// Drawing
	void drawShape(Window&);

public:
	Projectile();
	~Projectile();

	void update(sf::Vector2f);

	void draw(Window&);
};