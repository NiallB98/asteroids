#include "Audio.h"

Audio::Audio()
{
	load();
}

Audio::~Audio()
{

}

void Audio::playExplosion(int size)
{
	if (loadedExplosions[size-1] && not muted)
		soundExplosions[size-1].play();
}

void Audio::playShoot()
{
	if (loadedShoot && not muted)
		soundShoot.play();
}

void Audio::playRevive()
{
	if (loadedRevive && not muted)
		soundRevive.play();
}

void Audio::playGameStart()
{
	if (loadedGameStart && not muted)
		soundGameStart.play();
}

void Audio::playGameOver()
{
	if (loadedGameOver && not muted)
		soundGameOver.play();
}

void Audio::playLifeUp()
{
	if (loadedLifeUp && not muted)
		soundLifeUp.play();
}

void Audio::changeVolume(float volume)
{
	currentVolume = volume;

	for (int i = 0; i < soundExplosions.size(); i++)
		soundExplosions[i].setVolume(currentVolume);
	soundShoot.setVolume(currentVolume);
	soundRevive.setVolume(currentVolume);
	soundGameStart.setVolume(currentVolume);
	soundGameOver.setVolume(currentVolume);
	soundLifeUp.setVolume(currentVolume);
}

void Audio::increaseVolume(float increase)
{
	changeVolume(std::min(currentVolume + increase, 100.f));
}

void Audio::decreaseVolume(float decrease)
{
	changeVolume(std::max(currentVolume - decrease, 0.f));
}

void Audio::toggleMute()
{
	muted = not muted;
}

void Audio::draw()
{
	if (muted)
		drawMute();
	else
		drawVolume();
	
}

void Audio::loadExplosion(int size)
{
	if (bufferExplosions[size-1].loadFromFile("audio/effects/" + theme +"/explosion" + std::to_string(size) + ".wav"))
	{
		soundExplosions[size-1].setBuffer(bufferExplosions[size-1]);
		soundExplosions[size-1].setVolume(currentVolume);

		loadedExplosions[size-1] = true;
	}
}

void Audio::loadExplosions()
{
	for (int i = 0; i < bufferExplosions.size(); i++)
		loadExplosion(i);
}

void Audio::loadShoot()
{
	if (bufferShoot.loadFromFile("audio/effects/" + theme + "/shoot.wav"))
	{
		soundShoot.setBuffer(bufferShoot);
		soundShoot.setVolume(currentVolume);

		loadedShoot = true;
	}
}

void Audio::loadRevive()
{
	if (bufferRevive.loadFromFile("audio/effects/" + theme + "/revive.wav"))
	{
		soundRevive.setBuffer(bufferRevive);
		soundRevive.setVolume(currentVolume);

		loadedRevive = true;
	}
}

void Audio::loadGameStart()
{
	if (bufferGameStart.loadFromFile("audio/effects/" + theme + "/gameStart.wav"))
	{
		soundGameStart.setBuffer(bufferGameStart);
		soundGameStart.setVolume(currentVolume);

		loadedGameStart = true;
	}
}

void Audio::loadGameOver()
{
	if (bufferGameOver.loadFromFile("audio/effects/" + theme + "/gameOver.wav"))
	{
		soundGameOver.setBuffer(bufferGameOver);
		soundGameOver.setVolume(currentVolume);

		loadedGameOver = true;
	}
}

void Audio::loadLifeUp()
{
	if (bufferLifeUp.loadFromFile("audio/effects/" + theme + "/lifeUp.wav"))
	{
		soundLifeUp.setBuffer(bufferLifeUp);
		soundLifeUp.setVolume(currentVolume);

		loadedLifeUp = true;
	}
}

void Audio::load()
{
	loadExplosions();
	loadShoot();
	loadRevive();
	loadGameStart();
	loadGameOver();
	loadLifeUp();
}

void Audio::initShapes()
{

}

void Audio::drawVolume()
{

}

void Audio::drawMute()
{

}
