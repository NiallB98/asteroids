#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(sf::Vector2f windowDims)
{
	updateWindowDimensions(windowDims);
}

Menu::~Menu()
{
	
}

void Menu::updateWindowDimensions(sf::Vector2f windowDims)
{
	windowDimensions = windowDims;
}

void Menu::draw(Window& window)
{
	title.draw(window);
	menuControlHint.draw(window);
}

void Menu::update(sf::Event& event)
{
	menuControls.update(event);
}
void Menu::postUpdate()
{
	if (menuControls.playNow())
		goToPlay = true;
}

bool Menu::playNow()
{
	return goToPlay;
}

