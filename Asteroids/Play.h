#pragma once

#include "Window.h"

class Controls;
class Audio;

#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"
#include "Score.h"
#include "Lives.h"
#include "Explosion.h"

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
	std::vector<Explosion> explosions = std::vector<Explosion>(0);

	int maxAsteroids = 42 * 3;
	int startingAsteroids = 5;
	int maxPlayerProjectiles = 128;
	int maxEnemyProjectiles = 128;
	int maxExplosions = maxAsteroids + 1;

	void initPlayer();
	float playerRespawnDelaySeconds = 2.f;
	float playerDiedAtSeconds = -1.f;
	void respawnPlayer(sf::Clock);

	void initAsteroids();
	void initAsteroids(int);
	void spawnAsteroids(int);

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

	void updateExplosions();

	void updateLives(Audio&);

	bool startedDeathScreen = false;
	void showDeathScreen();

	// Post updating
	void checkExpiredObjects(sf::Clock&);
	void checkDeadObjects(sf::Clock&, Audio&);
	void checkSplittingAsteroids(sf::Clock&, Audio&);

	void postUpdatePlayer(sf::Clock&);
	void postUpdateAsteroids();
	void postUpdateProjectiles();

	void postUpdateExplosions(sf::Clock&);

	// Drawing
	void drawAsteroids(Window&);
	void drawPlayer(Window&);
	void drawProjectiles(Window&);
	void drawExplosions(Window&);
	void drawObjects(Window&);

	void drawScore(Window&);
	void drawLives(Window&);
	void drawUI(Window&);

	void addExplosion(Audio&, sf::Vector2f, int, sf::Clock&);

public:
	Play();
	Play(Audio&, sf::Vector2f);
	Play(Audio&, sf::Vector2f, int);
	~Play();

	void updateWindowDimensions(sf::Vector2f);

	// Events and update
	void pollEvents(sf::Event&, Audio&, sf::Clock&, Controls&);
	void update(sf::Event&, Audio&, sf::Clock& clock, Controls&);

	// Post updating
	void postUpdate(sf::Clock&, Audio&);

	// Drawing
	void draw(Window&);
};
