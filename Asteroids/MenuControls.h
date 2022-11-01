#pragma once

#include "Window.h"

class  MenuControls
{
private:
	void pollEvents(sf::Event&);
	bool goToPlay = false;

public:
	MenuControls();
	~MenuControls();

	void update(sf::Event&);
	void postUpdate();

	bool playNow();
};
