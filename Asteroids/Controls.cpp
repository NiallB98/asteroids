#include "Controls.h"

Controls::Controls()
{

}

Controls::~Controls()
{

}

sf::Keyboard::Key Controls::getKeyboardForward()
{
	return keyboardForward;
}

sf::Keyboard::Key Controls::getKeyboardShoot()
{
	return keyboardShoot;
}

sf::Keyboard::Key Controls::getKeyboardTurnLeft()
{
	return keyboardTurnLeft;
}

sf::Keyboard::Key Controls::getKeyboardTurnRight()
{
	return keyboardTurnRight;
}

bool Controls::isForwardPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected)
	{

	}
	
	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardForward());
}

bool Controls::isTurnLeftPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected)
	{

	}

	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardTurnLeft());
}

bool Controls::isTurnRightPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected)
	{

	}

	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardTurnRight());
}

bool Controls::isShootPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected)
	{
		
	}
	
	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardShoot());
}
