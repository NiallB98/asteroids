#pragma once

#include "Window.h"
#include "Player.h"
#include "Asteroid.h"

class Play
{
private:
	// Window dimensions
	sf::Vector2f windowDimensions;

	// Objects
	Player player;
	std::vector<Asteroid> asteroids;

	void initPlayer();

	int numAsteroids = 5;
	void initAsteroids();
	void initAsteroids(int);

	// Initial values for score and lives
	int score = 0;
	int lives = 3;

	// Drawing
	void drawAsteroids(Window&);
	void drawPlayer(Window&);
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
