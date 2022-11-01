#pragma once

#include "Window.h"

class Lives
{
private:
	int startingLives = 3;
	int lives = startingLives;

	// Drawing
	sf::Font font;
	sf::Text text;
	int characterSize = 32;
	sf::Color colour = sf::Color::White;
	sf::Vector2f pos = sf::Vector2f(8.f, 48.f);

	void initText();
	void updateText();

	bool showText = true;

public:
	Lives();
	~Lives();

	int getLives();

	void refresh();
	void loseOne();

	void initDeathScreenSettings();

	// Drawing
	void draw(Window&);
};
