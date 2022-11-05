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

sf::Keyboard::Key Controls::getKeyboardStartGame()
{
	return keyboardStartGame;
}

sf::Keyboard::Key Controls::getKeyboardQuitGame()
{
	return keyboardQuitGame;
}

bool Controls::isForwardPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, controllerForward))
			return true;
	}
	
	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardForward());
}

bool Controls::isTurnLeftPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::getAxisPosition(0, controllerTurningJoystick) < -controllerStickDeadzone)
			return true;
	}

	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardTurnLeft());
}

bool Controls::isTurnRightPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::getAxisPosition(0, controllerTurningJoystick) > controllerStickDeadzone)
			return true;
	}

	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardTurnRight());
}

bool Controls::isShootPressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, controllerShoot))
			return true;
		else if (sf::Joystick::getAxisPosition(0, triggers) < controllerTriggerShoot)
			return true;
	}
	
	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardShoot());
}

bool Controls::isStartGamePressed()
{
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, controllerStartGame) ||
			sf::Joystick::isButtonPressed(0, controllerAltStartGame))
			return true;
	}

	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardStartGame());
}

bool Controls::isQuitGamePressed()
{
	// Checking for joystick input first
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, controllerQuitGame))
			return true;
	}

	// Checking for keyboard input
	return sf::Keyboard::isKeyPressed(getKeyboardQuitGame());
}
