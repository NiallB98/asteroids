#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{
	
}

void Game::initLevels()
{
	levelPlay = Play(window.getDimensions(), 3);
}

// Reacts to input events that have occurred
void Game::pollEvents()
{
	while (window.pollEvent(event))
	{
		// Closing the game
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}
	}

	// Quit game key
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		window.close();
	}
}

// Handles frame by frame polling of events and game logic
void Game::update()
{
	pollEvents();

	switch (currentLevel)
	case 1:
		levelPlay.update(event);
}

// Controls rendering each new frame
void Game::render()
{
	window.clear();

	switch (currentLevel)
	{
	case 1:
		levelPlay.draw(window);
		break;
	default:
		break;
	}

	window.display();
	Game::clock.restart();
}

bool Game::isRunning()
{
	return window.isRunning();
}
