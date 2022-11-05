#pragma once

#include "Window.h"

class Controls
{
private:
	// Keyboard defaults
	sf::Keyboard::Key keyboardForward = sf::Keyboard::W;
	sf::Keyboard::Key keyboardShoot = sf::Keyboard::Space;
	sf::Keyboard::Key keyboardTurnLeft = sf::Keyboard::A;
	sf::Keyboard::Key keyboardTurnRight = sf::Keyboard::D;

	sf::Keyboard::Key keyboardStartGame = sf::Keyboard::Space;
	sf::Keyboard::Key keyboardQuitGame = sf::Keyboard::Escape;

	sf::Keyboard::Key keyboardVolumeUp = sf::Keyboard::Up;
	sf::Keyboard::Key keyboardVolumeDown = sf::Keyboard::Down;
	sf::Keyboard::Key keyboardMute = sf::Keyboard::M;

	// Get keyboard controls
	sf::Keyboard::Key getKeyboardForward();
	sf::Keyboard::Key getKeyboardShoot();
	sf::Keyboard::Key getKeyboardTurnLeft();
	sf::Keyboard::Key getKeyboardTurnRight();

	sf::Keyboard::Key getKeyboardStartGame();
	sf::Keyboard::Key getKeyboardQuitGame();

	sf::Keyboard::Key getKeyboardVolumeUp();
	sf::Keyboard::Key getKeyboardVolumeDown();
	sf::Keyboard::Key getKeyboardMute();

	// (Xbox) Controller buttons
	int buttonA = 0;
	int buttonB = 1;
	int buttonX = 2;
	int buttonY = 3;
	int leftBumper = 4;
	int rightBumper = 5;
	int buttonBack = 6;
	int buttonStart = 7;
	int leftStick = 8;
	int rightStick = 9;

	// (Xbox) Controller axis
	sf::Joystick::Axis leftStickX = sf::Joystick::Axis::X;
	sf::Joystick::Axis leftStickY = sf::Joystick::Axis::X;
	sf::Joystick::Axis rightStickX = sf::Joystick::Axis::U;
	sf::Joystick::Axis rightStickY = sf::Joystick::Axis::R;
	sf::Joystick::Axis triggers = sf::Joystick::Axis::Z;
	sf::Joystick::Axis dPadX = sf::Joystick::Axis::PovX;
	sf::Joystick::Axis dPadY = sf::Joystick::Axis::PovY;
	
	// Controller defaults
	int controllerForward = buttonA;
	int controllerShoot = rightBumper;
	int controllerTriggerShoot = -1; // 1 for left trigger, -1 for right trigger

	int controllerStartGame = buttonStart;
	int controllerAltStartGame = buttonA;
	int controllerQuitGame = buttonStart;

	sf::Joystick::Axis controllerTurningJoystick = leftStickX;

	sf::Joystick::Axis controllerVolumeDPadAxis = dPadX;
	int controllerMute = buttonBack;

	// (Max position for axis are +/-100.f)
	float controllerTriggerDeadzone = 10.f;
	float controllerStickDeadzone = 10.f;
	float controllerDPadDeadzone = 50.f;

public:
	Controls();
	~Controls();

	// Checking controls are pressed
	bool isForwardPressed();
	bool isTurnLeftPressed();
	bool isTurnRightPressed();
	bool isShootPressed();

	bool isStartGamePressed();
	bool isQuitGamePressed();

	bool isVolumeUpPressed();
	bool isVolumeDownPressed();
	bool isMutePressed();
};
