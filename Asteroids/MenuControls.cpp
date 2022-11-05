#include "MenuControls.h"

#include "Controls.h"

MenuControls::MenuControls()
{

}

MenuControls::~MenuControls()
{

}

void MenuControls::pollEvents(sf::Event& event, Controls& controls)
{
	if (controls.isStartGamePressed())
		goToPlay = true;
}

void MenuControls::update(sf::Event& event, Controls& controls)
{
	pollEvents(event, controls);
}

void MenuControls::postUpdate()
{
	
}

bool MenuControls::playNow()
{
	return goToPlay;
}
