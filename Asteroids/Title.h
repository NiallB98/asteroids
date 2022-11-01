#pragma once

#include "Window.h"

class Title
{
private:
	std::string titleString = "Asteroids";

	// Drawing
	sf::Font font;
	sf::Text text;
	int characterSize = 72;
	sf::Color colour = sf::Color::White;
	sf::Vector2f relPos = sf::Vector2f(0.f, -32.f);

	void initText();
	void updateText();
	sf::Vector2f getPos();

	sf::Vector2f windowDimensions = sf::Vector2f(720.f, 720.f);

public:
	Title();
	Title(sf::Vector2f);
	~Title();

	void updateWindowDimensions(sf::Vector2f);
	void draw(Window&);
};