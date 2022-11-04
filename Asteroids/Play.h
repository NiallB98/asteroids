#pragma once

#include "Window.h"

#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"
#include "Score.h"
#include "Lives.h"

class Play
{
private:
	// Window dimensions
	sf::Vector2f windowDimensions;

	// Objects
	Player player;
	std::vector<Asteroid> asteroids;
	std::vector<Projectile> playerProjectiles = std::vector<Projectile>(0);
	std::vector<Projectile> enemyProjectiles = std::vector<Projectile>(0);

	int maxAsteroids = 42 * 3;
	int maxPlayerProjectiles = 128;
	int maxEnemyProjectiles = 128;

	void initPlayer();

	void initAsteroids();
	void initAsteroids(int);

	void initProjectiles();

	// UI
	Score score;
	Lives lives;

	// Polling events
	void pollPlayerEvents(sf::Event, sf::Clock&);

	// Updating
	void updatePlayer();
	void updateAsteroids();
	void updateProjectiles();

	void showDeathScreen();

	// Post updating
	void checkExpiredObjects(sf::Clock&);
	void checkDeadObjects(sf::Clock&);

	void postUpdatePlayer(sf::Clock&);
	void postUpdateAsteroids();
	void postUpdateProjectiles();

	// Drawing
	void drawAsteroids(Window&);
	void drawPlayer(Window&);
	void drawProjectiles(Window&);
	void drawObjects(Window&);

	void drawScore(Window&);
	void drawLives(Window&);
	void drawUI(Window&);

public:
	Play();
	Play(sf::Vector2f, int);
	~Play();

	void updateWindowDimensions(sf::Vector2f);

	// Events and update
	void pollEvents(sf::Event&, sf::Clock&);
	void update(sf::Event&, sf::Clock& clock);

	// Post updating
	void postUpdate(sf::Clock&);

	// Drawing
	void draw(Window&);
};
