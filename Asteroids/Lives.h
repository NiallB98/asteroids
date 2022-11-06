#pragma once

#include "Window.h"

class Score;
class Audio;

class Lives
{
private:
	int maxLives = 5;
	int startingLives = 3;
	int lives = startingLives;
	int newLivesThreshold = 10000;
	int newLivesThresholdMultiplier = 1;

	// Drawing
	sf::Font font;
	sf::Text text;
	int characterSize = 32;
	sf::Color colour = sf::Color::White;
	sf::Vector2f pos = sf::Vector2f(8.f, 48.f);

	void initText();
	void updateText();

	void bonusLivesCheck(Score&, Audio&);

	bool showText = true;

public:
	Lives();
	~Lives();

	int getLives();

	void refresh();
	void loseOne();
	void addOne(Audio&);

	void initDeathScreenSettings();

	// Drawing
	void draw(Window&);

	void update(Score&, Audio&);
};
