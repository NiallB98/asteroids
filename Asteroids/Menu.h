#pragma once

#include "Window.h"
#include "Title.h"
#include "MenuControlHint.h"
#include "MenuControls.h"

class Menu
{
private:
	sf::Vector2f windowDimensions = sf::Vector2f(720.f, 720.f);

	Title title = Title(windowDimensions);
	MenuControlHint menuControlHint = MenuControlHint(windowDimensions);
	MenuControls menuControls;

	bool goToPlay = false;

public:
	Menu();
	Menu(sf::Vector2f);
	~Menu();

	void updateWindowDimensions(sf::Vector2f);
	void draw(Window&);

	void update(sf::Event&);
	void postUpdate();

	bool playNow();
};