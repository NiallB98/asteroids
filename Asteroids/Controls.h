#pragma once

#include "Window.h"

class Controls
{
private:
	//Keyboard
	sf::Keyboard::Key keyboardForward = sf::Keyboard::W;
	sf::Keyboard::Key keyboardShoot = sf::Keyboard::Space;
	sf::Keyboard::Key keyboardTurnLeft = sf::Keyboard::A;
	sf::Keyboard::Key keyboardTurnRight = sf::Keyboard::D;

	// Controller
	//

public:
	Controls();
	~Controls();

	// Keyboard
	sf::Keyboard::Key getKeyboardForward();
	sf::Keyboard::Key getKeyboardShoot();
	sf::Keyboard::Key getKeyboardTurnLeft();
	sf::Keyboard::Key getKeyboardTurnRight();

	// Controller
	//

	// Checking controls are pressed
	bool isForwardPressed();
	bool isTurnLeftPressed();
	bool isTurnRightPressed();
	bool isShootPressed();
};
