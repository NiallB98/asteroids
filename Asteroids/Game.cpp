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
void Game::pollGlobalEvents()
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
	pollGlobalEvents();

	switch (currentLevel)
	{
	case MENU:

		break;
	case PLAY:
		levelPlay.update(event);
		break;
	default:
		break;
	}
}

// Controls rendering each new frame
void Game::render()
{
	window.clear();

	switch (currentLevel)
	{
	case MENU:

		break;
	case PLAY:
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
