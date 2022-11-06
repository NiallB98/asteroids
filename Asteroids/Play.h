#pragma once

#include "Window.h"

class Controls;
class Audio;

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
	void pollPlayerEvents(sf::Event, Audio&, sf::Clock&, Controls&);

	// Updating
	void updatePlayer();
	void updateAsteroids();
	void updateProjectiles();

	void updateLives();

	void showDeathScreen();

	// Post updating
	void checkExpiredObjects(sf::Clock&);
	void checkDeadObjects(sf::Clock&);
	void checkSplittingAsteroids();

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
	Play(Audio&, sf::Vector2f, int);
	~Play();

	void updateWindowDimensions(sf::Vector2f);

	// Events and update
	void pollEvents(sf::Event&, Audio&, sf::Clock&, Controls&);
	void update(sf::Event&, Audio&, sf::Clock& clock, Controls&);

	// Post updating
	void postUpdate(sf::Clock&);

	// Drawing
	void draw(Window&);
};
