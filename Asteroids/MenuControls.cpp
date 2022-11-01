#include "MenuControls.h"

MenuControls::MenuControls()
{

}

MenuControls::~MenuControls()
{

}

void MenuControls::pollEvents(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		goToPlay = true;
}

void MenuControls::update(sf::Event& event)
{
	pollEvents(event);
}

void MenuControls::postUpdate()
{
	
}

bool MenuControls::playNow()
{
	return goToPlay;
}
