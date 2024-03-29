#pragma once

#include "Window.h"

class Score
{
private:
	int score = 0;

	bool scoreLocked = false;

	std::vector<int> asteroidSizeScores = std::vector<int>{25, 100, 250};
	int ufoScore = 150;
	int cometScore = 1000;

	// Drawing
	sf::Font font;
	sf::Text text;
	int characterSize = 32;
	sf::Color colour = sf::Color::White;
	sf::Vector2f pos = sf::Vector2f(8.f, 8.f);

	void initText();
	void updateText();

	bool textLocked = false;

	// Death screen settings
	int deathScreenCharacterSize = 100;
	sf::Vector2f deathScreenPosRelToCentre = sf::Vector2f(0.f, 0.f);

public:
	Score();
	~Score();

	int getScore();

	void asteroidHit(int);
	void ufoHit();
	void cometHit();

	void initDeathScreenSettings(sf::Vector2f);

	// Drawing
	void draw(Window&);
};