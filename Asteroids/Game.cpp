#include "Game.h"

Game::Game()
{
	initLevel(currentLevel);
}

Game::~Game()
{
	delete levelMenu;
	delete levelPlay;
}

void Game::initLevels()
{
	initLevel(MENU);
	initLevel(PLAY);
}

void Game::initLevel(int level)
{
	switch (level)
	{
	case MENU:
		levelMenu = new Menu(window.getDimensions());
		break;
	case PLAY:
		levelPlay = new Play(audio, window.getDimensions(), 3);
		break;
	default:
		break;
	}

	clock.restart();
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
	if (controls.isQuitGamePressed())
	{
		window.close();
	}
	
	// Volume controls
	if (controls.isVolumeUpPressed())
	{
		audio.increaseVolume(5.f);
	}
	if (controls.isVolumeDownPressed())
	{
		audio.decreaseVolume(5.f);
	}
	if (controls.isMutePressed())
	{
		audio.toggleMute();
	}
}

// Handles frame by frame polling of events and game logic
void Game::update()
{
	pollGlobalEvents();

	audio.update(window.getDimensions(), clock);

	switch (currentLevel)
	{
	case MENU:
		levelMenu->update(event, controls);
		break;
	case PLAY:
		levelPlay->update(event, audio, clock, controls);
		break;
	default:
		break;
	}
}

void Game::changeLevel(int level)
{
	switch (currentLevel)
	{
	case MENU:
		delete levelMenu;
		levelMenu = NULL;
		break;
	case PLAY:
		delete levelPlay;
		levelPlay = NULL;
		break;
	}
	
	currentLevel = level;
	initLevel(currentLevel);
}

void Game::levelChanging()
{
	switch (currentLevel)
	{
	case MENU:
		if (levelMenu->playNow())
			changeLevel(PLAY);
		break;
	case PLAY:
		break;
	default:
		break;
	}
}

void Game::postUpdate()
{
	audio.postUpdate();
	
	switch (currentLevel)
	{
	case MENU:
		levelMenu->postUpdate();
		levelChanging();
		break;
	case PLAY:
		levelPlay->postUpdate(clock, audio);
		levelChanging();
		break;
	default:
		break;
	}
}

void Game::globalPreDraw()
{

}

void Game::globalPostDraw()
{
	// Drawing volume when it is updated
	audio.draw(window);
}

// Controls rendering each new frame
void Game::render()
{
	window.clear();

	globalPreDraw();

	switch (currentLevel)
	{
	case MENU:
		levelMenu->draw(window);
		break;
	case PLAY:
		levelPlay->draw(window);
		break;
	default:
		break;
	}

	globalPostDraw();

	window.display();
	Game::deltaTimeClock.restart();
}

bool Game::isRunning()
{
	return window.isRunning();
}
