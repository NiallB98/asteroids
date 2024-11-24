#pragma once
class Object
{
	bool alive = true;
	bool invincible = true;
	float invincibleDurationSecs = 3.f;
	float playerStartSeconds = 0.f;

	void removeInvincible();
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

	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	float maxSpeed = 4.f;
	float acceleration = 0.1f;

	void updatePos(sf::Vector2f);

	// Collsion checking
	bool collisionWithAsteroids(std::vector<Asteroid>&);
	bool collisionChecks(std::vector<Asteroid>&);

public:
	Player();
	Player(sf::Clock);
	~Player();

	bool isAlive();
	bool isInvincible();

	// Movement
	void setPos(sf::Vector2f);
	sf::Vector2f getPos();
	void rotate(bool);
	void accelerate();

	// Updating and events
	void update(sf::Vector2f, std::vector<Asteroid>&);
	void postUpdate(sf::Clock&);

	void draw(Window&);
};
