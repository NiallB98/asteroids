#include "Play.h"

Play::Play()
{
	updateWindowDimensions(sf::Vector2f(720.f, 720.f));
	initPlayer();
	initAsteroids();
}

Play::Play(sf::Vector2f windowDims, int num)
{
	updateWindowDimensions(windowDims);
	initPlayer();
	initAsteroids(num);
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
	numAsteroids = num;
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
	initAsteroids(numAsteroids);
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

void Play::drawObjects(Window& window)
{
	drawAsteroids(window);
	drawPlayer(window);
}

// Drawing UI
void Play::drawScore(Window&)
{

}

void Play::drawLives(Window&)
{

}

void Play::drawUI(Window& window)
{

}

// Main drawing function
void Play::draw(Window& window)
{
	drawObjects(window);
	drawUI(window);
}

void Play::pollEvents(sf::Event& event)
{
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
		player.rotate(rotationDir + 1);
	}
}

// Handles polling events and game logic
void Play::update(sf::Event& event)
{
	pollEvents(event);
}
