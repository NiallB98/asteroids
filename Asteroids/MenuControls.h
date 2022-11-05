#pragma once

#include "Window.h"

class Controls;

class  MenuControls
{
private:
	void pollEvents(sf::Event&, Controls&);
	bool goToPlay = false;

public:
	MenuControls();
	~MenuControls();

	void update(sf::Event&, Controls&);
	void postUpdate();

	bool playNow();
};
