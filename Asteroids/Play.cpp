#include "Play.h"

#include "Controls.h"
#include "Audio.h"

Play::Play()
{
	updateWindowDimensions(sf::Vector2f(720.f, 720.f));
	initPlayer();
	initAsteroids();
	initProjectiles();
}

Play::Play(Audio& audio, sf::Vector2f windowDims, int num)
{
	updateWindowDimensions(windowDims);
	initPlayer();
	initAsteroids(num);
	initProjectiles();

	audio.playGameStart();
}

Play::~Play()
{
	
}

void Play::updateWindowDimensions(sf::Vector2f windowDims)
{
	windowDimensions = windowDims;
}

void Play::initPlayer()
{
	player.setPos(sf::Vector2f(windowDimensions.x / 2, windowDimensions.y / 2));
}

void Play::respawnPlayer(sf::Clock clock)
{
	player = Player(clock);
	initPlayer();
	lives.loseOne();

	playerDiedAtSeconds = -1.f;
}

// This method sets the random positions and velocities of each asteroid
void Play::initAsteroids(int num)
{
	asteroids.reserve(maxAsteroids);
	asteroids = std::vector<Asteroid>(num);

	// Setting asteroids to start at random positions
	float minX = 0.f;
	float maxX = windowDimensions.x;
	float minY = 0.f;
	float maxY = windowDimensions.y;

	for (int i = 0; i < asteroids.size(); i++)
	{
		float randX = static_cast<float>(rand() % static_cast<int>(maxX - minX)) + minX;
		float randY = static_cast<float>(rand() % static_cast<int>(maxY - minY)) + minY;

		asteroids[i].setPos(sf::Vector2f(randX, randY));
	}
}

void Play::initAsteroids()
{
	initAsteroids(5);
}

void Play::initProjectiles()
{
	playerProjectiles.reserve(maxPlayerProjectiles);
}

// Drawing objects
void Play::drawPlayer(Window& window)
{
	player.draw(window);
}

void Play::drawAsteroids(Window& window)
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i].isAlive())
			asteroids[i].draw(window);
	}
}

void Play::drawProjectiles(Window& window)
{
	// Player projectiles
	for (int i = 0; i < playerProjectiles.size(); i++)
		playerProjectiles[i].draw(window);

	// Enemy projectiles
	for (int i = 0; i < enemyProjectiles.size(); i++)
		enemyProjectiles[i].draw(window);
}

void Play::drawObjects(Window& window)
{
	drawAsteroids(window);
	drawPlayer(window);
	drawProjectiles(window);
	drawExplosions(window);
}

void Play::drawExplosions(Window& window)
{
	for (int i = 0; i < explosions.size(); i++)
		explosions[i].draw(window);
}

// Drawing UI
void Play::drawScore(Window& window)
{
	score.draw(window);
}

void Play::drawLives(Window& window)
{
	lives.draw(window);
}

void Play::drawUI(Window& window)
{
	drawScore(window);
	drawLives(window);
}

void Play::addExplosion(Audio& audio, sf::Vector2f pos, int size, sf::Clock& clock)
{
	std::vector<Explosion>::iterator p = explosions.end();
	explosions.insert(p, Explosion(audio, pos, size, clock));
}

// Main drawing function
void Play::draw(Window& window)
{
	drawObjects(window);
	drawUI(window);
}

void Play::pollPlayerEvents(sf::Event event, Audio& audio, sf::Clock& clock, Controls& controls)
{
	player.pollEvents(event, audio, clock, controls, playerProjectiles);
}

void Play::pollEvents(sf::Event& event, Audio& audio, sf::Clock& clock, Controls& controls)
{
	pollPlayerEvents(event, audio, clock, controls);
}

void Play::updatePlayer()
{
	player.update(windowDimensions, asteroids);
}

void Play::updateAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
		asteroids[i].update(windowDimensions, playerProjectiles);
}

void Play::updateProjectiles()
{
	// Player projectiles
	for (int i = 0; i < playerProjectiles.size(); i++)
		playerProjectiles[i].update(windowDimensions, asteroids);

	// Enemy projectiles
	for (int i = 0; i < enemyProjectiles.size(); i++)
		enemyProjectiles[i].update(windowDimensions, asteroids);
}

void Play::updateExplosions()
{
	for (int i = 0; i < explosions.size(); i++)
		explosions[i].update();
}

void Play::updateLives(Audio& audio)
{
	lives.update(score, audio);
}

// Handles polling events and game logic
void Play::update(sf::Event& event, Audio& audio, sf::Clock& clock, Controls& controls)
{
	pollEvents(event, audio, clock, controls);

	updatePlayer();
	updateAsteroids();
	// Update projectiles last so as objects colliding with them can ignore projectile speed in collision checks
	updateProjectiles();
	updateExplosions();

	updateLives(audio);
}

// Post update stage
void Play::postUpdatePlayer(sf::Clock& clock)
{
	player.postUpdate(clock);
}

void Play::postUpdateAsteroids()
{
	// Player projectiles
	for (int i = 0; i < asteroids.size(); i++)
		asteroids[i].postUpdate(score);
}

void Play::postUpdateProjectiles()
{
	// Player projectiles
	for (int i = 0; i < playerProjectiles.size(); i++)
		playerProjectiles[i].postUpdate();

	// Enemy projectiles
	for (int i = 0; i < enemyProjectiles.size(); i++)
		enemyProjectiles[i].postUpdate();
}

void Play::postUpdateExplosions(sf::Clock& clock)
{
	for (int i = 0; i < explosions.size(); i++)
		explosions[i].postUpdate(clock);
}

void Play::showDeathScreen()
{
	lives.initDeathScreenSettings();
	score.initDeathScreenSettings(windowDimensions);
}

void Play::checkExpiredObjects(sf::Clock& clock)
{
	// Checking player projectiles
	for (int i = playerProjectiles.size() - 1; i >= 0; i--)
	{
		if (playerProjectiles[i].hasExpired(clock))
		{
			playerProjectiles.erase(playerProjectiles.begin() + i);
		}
	}

	// Checking enemy projectiles
	for (int i = enemyProjectiles.size() - 1; i >= 0; i--)
	{
		if (enemyProjectiles[i].hasExpired(clock))
		{
			enemyProjectiles.erase(enemyProjectiles.begin() + i);
		}
	}

	// Checking explosions
	for (int i = explosions.size() - 1; i >= 0; i--)
	{
		if (explosions[i].hasExpired())
		{
			explosions.erase(explosions.begin() + i);
		}
	}
}

void Play::checkDeadObjects(sf::Clock& clock, Audio& audio)
{
	// Asteroids
	for (int i = asteroids.size() - 1; i >= 0; i--)
	{
		if (not asteroids[i].isAlive())
		{
			addExplosion(audio, asteroids[i].getPos(), 1, clock);
			asteroids.erase(asteroids.begin() + i);
		}
	}
	
	// Player
	if (not player.isAlive() && lives.getLives() > 0 && playerDiedAtSeconds < 0.f)
	{
		addExplosion(audio, player.getPos(), 0, clock);
		playerDiedAtSeconds = clock.getElapsedTime().asSeconds();
	}
	else if (not player.isAlive() && lives.getLives() > 0 && playerDiedAtSeconds +
		playerRespawnDelaySeconds < clock.getElapsedTime().asSeconds())
		respawnPlayer(clock);
	else if (not player.isAlive() && not startedDeathScreen && lives.getLives() <= 0)
	{
		addExplosion(audio, player.getPos(), 1, clock);
		showDeathScreen();
		startedDeathScreen = true;
	}

	// Player projectiles
	for (int i = playerProjectiles.size() - 1; i >= 0; i--)
	{
		if (not playerProjectiles[i].isAlive())
		{
			playerProjectiles.erase(playerProjectiles.begin() + i);
		}
	}
}

void Play::checkSplittingAsteroids(sf::Clock& clock, Audio& audio)
{
	std::vector<sf::Vector2f> newAsteroidPositions;
	newAsteroidPositions.reserve(asteroids.size());
	std::vector<sf::Vector2f>::iterator p1;

	std::vector<int> newAsteroidSizes;
	newAsteroidSizes.reserve(asteroids.size());
	std::vector<int>::iterator p2;

	// Getting positions and sizes for new asteroids
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i].doSplit())
		{
			addExplosion(audio, asteroids[i].getPos(), asteroids[i].getSize() + 1, clock);

			p1 = newAsteroidPositions.end();
			p2 = newAsteroidSizes.end();

			newAsteroidPositions.insert(p1, asteroids[i].getPos());
			newAsteroidSizes.insert(p2, asteroids[i].getSize());

			asteroids[i].clearSplit();
		}
	}

	// Adding in new asteroids
	std::vector<Asteroid>::iterator p = asteroids.end();
	for (int i = 0; i < newAsteroidPositions.size(); i++)
	{
		asteroids.insert(p, Asteroid(newAsteroidPositions[i], newAsteroidSizes[i]));
		p = asteroids.end();
	}
}

void Play::postUpdate(sf::Clock& clock, Audio& audio)
{
	postUpdatePlayer(clock);
	postUpdateAsteroids();
	postUpdateProjectiles();
	postUpdateExplosions(clock);

	checkExpiredObjects(clock);
	checkDeadObjects(clock, audio);
	checkSplittingAsteroids(clock, audio);
}
