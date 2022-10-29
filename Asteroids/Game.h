#pragma once

#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Window.h"
#include "Play.h"

#define MENU 0
#define PLAY 1

class Game
{
private:
	Window window;
	sf::Event event;

	// Levels
	int currentLevel = 1;
	Play levelPlay;
	void initLevels();

	void pollGlobalEvents();

public:
	Game();
	~Game();

	sf::Clock clock;																				// To keep track of delta time use "sf::Time dt = clock.getElapsedTime();" (Use dt.asMilliseconds())

	void update();
	void render();

	bool isRunning();
};
