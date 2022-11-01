#include "Play.h"

Play::Play()
{
	updateWindowDimensions(sf::Vector2f(720.f, 720.f));
	initPlayer();
	initAsteroids();
	initProjectiles();
}

Play::Play(sf::Vector2f windowDims, int num)
{
	updateWindowDimensions(windowDims);
	initPlayer();
	initAsteroids(num);
	initProjectiles();
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

// Main drawing function
void Play::draw(Window& window)
{
	drawObjects(window);
	drawUI(window);
}

void Play::pollPlayerEvents(sf::Event event)
{
	player.pollEvents(event);
}

void Play::pollEvents(sf::Event& event)
{
	pollPlayerEvents(event);
}

void Play::updatePlayer()
{
	player.update(windowDimensions, asteroids);
}

void Play::updateAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
		asteroids[i].update(windowDimensions);
}

void Play::updateProjectiles()
{
	// Player projectiles
	for (int i = 0; i < playerProjectiles.size(); i++)
		playerProjectiles[i].update(windowDimensions);

	// Enemy projectiles
	for (int i = 0; i < enemyProjectiles.size(); i++)
		enemyProjectiles[i].update(windowDimensions);
}

// Handles polling events and game logic
void Play::update(sf::Event& event)
{
	pollEvents(event);

	updatePlayer();
	updateAsteroids();
	updateProjectiles();
}

// Post update stage
void Play::postUpdatePlayer()
{
	player.postUpdate();
}

void Play::postUpdateAsteroids()
{
	// Player projectiles
	for (int i = 0; i < asteroids.size(); i++)
		asteroids[i].postUpdate();
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

void Play::showDeathScreen()
{
	lives.initDeathScreenSettings();
	score.initDeathScreenSettings(windowDimensions);
}

void Play::postUpdate()
{
	postUpdatePlayer();
	postUpdateAsteroids();
	postUpdateProjectiles();

	if (not player.isAlive() && lives.getLives() > 0)
	{
		player = Player();
		initPlayer();
		lives.loseOne();
	}
	else if (not player.isAlive())
	{
		showDeathScreen();
	}
}
