#pragma once

#include "Window.h"
#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"
#include "Score.h"

class Play
{
private:
	// Window dimensions
	sf::Vector2f windowDimensions;

	// Objects
	Player player;
	std::vector<Asteroid> asteroids;
	Projectile projectile;

	void initPlayer();

	int numAsteroids = 5;
	void initAsteroids();
	void initAsteroids(int);

	// UI
	Score score;

	// Polling events
	void pollPlayerEvents(sf::Event);

	// Updating
	void updatePlayer();
	void updateAsteroids();
	void updateProjectiles();

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
	void pollEvents(sf::Event&);
	void update(sf::Event&);

	// Drawing
	void draw(Window&);
};
