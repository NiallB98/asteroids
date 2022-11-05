#include "Window.h"

class Asteroid;

class Projectile
{
private:
	sf::Vector2f pos = sf::Vector2f(50.f, 50.f);

	float createdAtSeconds = 0.f;
	float lifespanSeconds = 0.8f;

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
	float rotationDegrees = 0.f;

	void move();
	void setPos(sf::Vector2f);
	void updatePos(sf::Vector2f);

	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	float maxSpeed = 16.f;

	// Collisions
	bool hasBeenHit = false;
	bool collisionWithAsteroids(std::vector<Asteroid>&);
	bool collisionChecks(std::vector<Asteroid>&);

	void die();
	bool alive = true;

public:
	Projectile();
	Projectile(sf::Vector2f, float, sf::Clock&);
	~Projectile();

	sf::VertexArray getCollider();

	bool isAlive();

	void update(sf::Vector2f, std::vector<Asteroid>&);
	void postUpdate();

	bool hasExpired(sf::Clock&);

	void draw(Window&);
};
