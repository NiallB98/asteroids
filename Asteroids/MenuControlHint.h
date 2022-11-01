#pragma once

#include "Window.h"

class MenuControlHint
{
private:
	std::string controlHintString = "Press Space to Play";

	// Drawing
	sf::Font font;
	sf::Text text;
	int characterSize = 32;
	sf::Color colour = sf::Color::White;
	sf::Vector2f relPos = sf::Vector2f(0.f, 64.f);

	void initText();
	void updateText();
	sf::Vector2f getPos();

	sf::Vector2f windowDimensions = sf::Vector2f(720.f, 720.f);

public:
	MenuControlHint();
	MenuControlHint(sf::Vector2f);
	~MenuControlHint();

	void updateWindowDimensions(sf::Vector2f);
	void draw(Window&);
};
