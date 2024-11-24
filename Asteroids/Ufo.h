#pragma once

#include "Window.h"

class Asteroid;
class Projectile;
class Controls;
class Audio;
class Player;

class Ufo
{
private:
	bool alive = true;

	void die();

	// Collider
	bool doDrawCollider = true;
	sf::CircleShape collider;
	sf::Color colliderColourNotHit = sf::Color(116, 177, 210, 100);
	sf::Color colliderColourHit = sf::Color(163, 203, 225, 150);
	void initCollider();

	// Shape
	int vertices = 3 + 1;
	sf::Color vertexColour = sf::Color::White;
	sf::VertexArray shape;
	void initShape();
	void initVertexArray();
	void updateVertexArray();
	std::vector<sf::Vector2f> vertexRelPos = std::vector<sf::Vector2f>(vertices);

	// Drawing
	void drawCollider(Window&);
	void drawShape(Window&);

	// Movement
	sf::Vector2f pos = sf::Vector2f(0.f, 0.f);

	float rotationDegrees = 0.f;
	float rotationSpeed = 4.f;

	sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
	float speed = 4.f;

	void updatePos(sf::Vector2f);

	// Collsion checking
	bool collisionWithPlayer(Player&);
	bool collisionChecks(Player&);

	// Firing projectiles
	sf::Vector2f cannonPos;
	float fireCooldownSeconds = 0.5f;
	float lastFiredSeconds = -fireCooldownSeconds / 2.f;
	void fireProjectile(std::vector<Projectile>&, Audio&, sf::Clock&);

public:
	Ufo();
	Ufo(sf::Clock);
	~Ufo();

	bool isAlive();

	// Movement
	void setPos(sf::Vector2f);
	sf::Vector2f getPos();

	// Updating and events
	void update(sf::Vector2f, std::vector<Asteroid>&);
	void postUpdate(sf::Clock&);

	void draw(Window&);
};
