#pragma once

#include "Window.h"

class AudioBar
{
private:
	// Timing
	bool expired = false;
	float createdTimeSeconds = 0.f;
	float lifetimeSolidSeconds = 2.f;
	float lifetimeTransparentSeconds = 1.f;
	float totalLifetime = lifetimeSolidSeconds + lifetimeTransparentSeconds;

	// Volume
	float maxVolume = 100.f;
	float volume = 50.f;
	bool muted = false;

	// Shapes
	sf::Vector2f posFromTopRight = sf::Vector2f(8.f, 8.f);
	float minHeight = 64.f;
	float heightToWinHeightRatio = 0.1;
	float widthToHeightRatio = 0.3;
	sf::Vector2f foregroundPadding = sf::Vector2f(2.f, 3.f);
	sf::RectangleShape backgroundRect;
	sf::RectangleShape foregroundRect;
	float maxTransparency = 255.f;
	float transparency = maxTransparency;
	sf::Vector3f backgroundColourRGB = sf::Vector3f(255.f, 255.f, 255.f);
	sf::Vector3f backgroundColourRGBMuted = sf::Vector3f(200.f, 200.f, 200.f);
	sf::Vector3f foregroundColourRGB = sf::Vector3f(0.f, 0.f, 0.f);
	sf::Vector3f foregroundColourRGBMuted = sf::Vector3f(150.f, 150.f, 150.f);

	// Speaker symbol here
	void initShapes(sf::Vector2f);
	
	void updateVolumeBarHeight();
	void updateShapes();
	void changeTransparency(float);

public:
	AudioBar();
	AudioBar(sf::Vector2f, sf::Clock, float, bool);
	~AudioBar();

	void changeVolume(float);

	void update(sf::Clock&);

	bool hasExpired();

	void draw(Window&);
};