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
#include "Menu.h"
#include "Controls.h"
#include "Audio.h"

enum class Levels {
	MENU = 0,
	PLAY
};

class Game
{
private:
	Window window;
	sf::Event event;

	Controls controls;

	Audio audio;

	Levels currentLevel{ Levels::MENU };

	Play* levelPlay;
	Menu* levelMenu;
	void initLevels();
	void initLevel(Levels);

	void levelChanging();
	void changeLevel(Levels);

	void pollGlobalEvents();

public:
	Game();
	~Game();

	sf::Clock deltaTimeClock;																				// To keep track of delta time use "sf::Time dt = clock.getElapsedTime();" (Use dt.asMilliseconds())
	sf::Clock clock;

	void update();
	void postUpdate();
	void globalPreDraw();
	void globalPostDraw();
	void render();

	bool isRunning();
};
