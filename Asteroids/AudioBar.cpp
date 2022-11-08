#include "AudioBar.h"

AudioBar::AudioBar()
{
	initShapes(sf::Vector2f(720.f, 720.f));
}

AudioBar::AudioBar(sf::Vector2f windowDims, sf::Clock clock, float newVolume)
{
	createdTimeSeconds = clock.getElapsedTime().asSeconds();
	volume = newVolume;

	initShapes(windowDims);
}

AudioBar::~AudioBar()
{

}

void AudioBar::updateVolumeBarHeight()
{
	float percent = volume / maxVolume;
	float maxHeight = backgroundRect.getLocalBounds().height - foregroundPadding.y * 2.f;

	foregroundRect.setSize(sf::Vector2f(backgroundRect.getLocalBounds().width - foregroundPadding.x * 2.f, percent * maxHeight));
}

void AudioBar::initShapes(sf::Vector2f windowDims)
{
	changeTransparency(transparency);

	// Working out dimensions
	float backgroundHeight = std::max(windowDims.y * heightToWinHeightRatio, minHeight);
	float backgroundWidth = backgroundHeight * widthToHeightRatio;
	sf::Vector2f backgroundDims = sf::Vector2f(backgroundWidth, backgroundHeight);

	backgroundRect.setSize(backgroundDims);
	updateVolumeBarHeight();
	

	// Setting positions
	sf::Vector2f backgroundPos = sf::Vector2f(windowDims.x - posFromTopRight.x - backgroundWidth, posFromTopRight.y);
	backgroundRect.setPosition(backgroundPos);

	foregroundRect.setOrigin(sf::Vector2f(0.f, foregroundRect.getLocalBounds().height));
	foregroundRect.setPosition(sf::Vector2f(backgroundPos.x + foregroundPadding.x,
		backgroundDims.y + backgroundPos.y - foregroundPadding.y));
}

void AudioBar::updateShapes()
{
	updateVolumeBarHeight();
}

void AudioBar::changeTransparency(float newTransparency)
{
	transparency = newTransparency;
	backgroundRect.setFillColor(sf::Color(backgroundColourRGB.x, backgroundColourRGB.y, backgroundColourRGB.z, transparency));
	foregroundRect.setFillColor(sf::Color(foregroundColourRGB.x, foregroundColourRGB.y, foregroundColourRGB.z, transparency));
}

void AudioBar::changeVolume(float newVolume)
{
	volume = newVolume;

	updateShapes();
}

void AudioBar::update(sf::Clock& clock)
{
	float currentTimeSeconds = clock.getElapsedTime().asSeconds();
	if (createdTimeSeconds + lifetimeSolidSeconds + lifetimeTransparentSeconds < currentTimeSeconds)
		expired = true;
	else if (createdTimeSeconds + lifetimeSolidSeconds < currentTimeSeconds)
	{
		float newTransparency = maxTransparency - std::min(maxTransparency * 
			std::abs((currentTimeSeconds - createdTimeSeconds - lifetimeSolidSeconds) / lifetimeTransparentSeconds),
			maxTransparency);

		changeTransparency(newTransparency);
	}
}

void AudioBar::draw(Window& window)
{
	window.draw(backgroundRect);
	window.draw(foregroundRect);
}

bool AudioBar::hasExpired()
{
	return expired;
}
