#include "Player.h"

#include "Asteroid.h"
#include "Projectile.h"

Player::Player()
{
	initCollider();
	initShape();
}

Player::~Player()
{
	
}

bool Player::isAlive()
{
	return alive;
}

bool Player::isInvincible()
{
	return invincible;
}

void Player::removeInvincible()
{
	invincible = false;
	doDrawCollider = false;
}

void Player::die()
{
	alive = false;
}

// Initialising the shape and collider
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

	cannonPos = shape[0].position;
}

void Player::initVertexArray()
{
	for (int i = 0; i < vertices; i++)
	{
		if (i == vertices - 1)
		{
			vertexRelPos[i] = vertexRelPos[0];
		}

		// Defining the colour of the shape
		shape[i].color = vertexColour;
	}
	
	updateVertexArray();
}

void Player::initShape()
{
	shape = sf::VertexArray(sf::LinesStrip, vertices);

	initVertexArray();
}

void Player::initCollider()
{
	collider = sf::CircleShape(15.f);
	collider.setPosition(pos);
	collider.setOrigin(sf::Vector2f(15.f, 15.f));
	collider.setFillColor(colliderColourNotHit);
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
	if (isAlive())
	{
		drawCollider(window);
		drawShape(window);
	}
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

void Player::accelerate()
{
	float accelerationX = acceleration * sinf(PI * rotationDegrees / 180.f);
	float accelerationY = -acceleration * cosf(PI * rotationDegrees / 180.f);

	speed = sf::Vector2f(speed.x + accelerationX, speed.y + accelerationY);

	// Ensuring the overall speed has not exceeded the maximum limit
	float overMaxSpeedFactor = (std::sqrtf(speed.x * speed.x + speed.y * speed.y) - maxSpeed) / maxSpeed;
	if (overMaxSpeedFactor > 0.f)
	{
		speed = sf::Vector2f(speed.x - speed.x * overMaxSpeedFactor, speed.y - speed.y * overMaxSpeedFactor);
	}
}

void Player::updatePos(sf::Vector2f windowDims)
{
	setPos(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));

	if (mvmt::loopPos(windowDims, pos))
		setPos(pos);
}

void Player::fireProjectile(std::vector<Projectile>& playerProjectiles, sf::Clock& clock)
{
	if (lastFiredSeconds < clock.getElapsedTime().asSeconds() - fireCooldownSeconds && isAlive())
	{
		std::vector<Projectile>::iterator p = playerProjectiles.end();
		playerProjectiles.insert(p, Projectile(cannonPos, rotationDegrees, clock));

		lastFiredSeconds = clock.getElapsedTime().asSeconds();
	}
}

void Player::pollEvents(sf::Event& event, sf::Clock& clock, std::vector<Projectile>& playerProjectiles)
{
	// Rotation
	int rotationDir = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		rotationDir++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		rotationDir--;
	}
	if (rotationDir != 0)
	{
		rotate(rotationDir + 1);
	}

	// Forward movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		accelerate();
	// Firing projectiles
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		fireProjectile(playerProjectiles, clock);
}

// Collision checking
bool Player::collisionWithAsteroids(std::vector<Asteroid>& asteroids)
{
	for (int i = 0; i < asteroids.size(); i++)
		if (clsn::circlesColliding(collider, asteroids[i].getCollider()))
			return true;
	return false;
}

bool Player::collisionChecks(std::vector<Asteroid>& asteroids)
{
	bool collided = (collisionWithAsteroids(asteroids));

	if (collided)
	{
		if (doDrawCollider)
			collider.setFillColor(colliderColourHit);
		if (not isInvincible() and isAlive())
			die();
	}
	else if (doDrawCollider)
		collider.setFillColor(colliderColourNotHit);

	return collided;
}

// Update
void Player::update(sf::Vector2f windowDims, std::vector<Asteroid>& asteroids)
{
	if (isAlive())
	{
		updatePos(windowDims);
		collisionChecks(asteroids);
	}
}

void Player::postUpdate(sf::Clock& clock)
{
	if (isInvincible() && invincibleDurationSecs < clock.getElapsedTime().asSeconds())
		removeInvincible();
}
