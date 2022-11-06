#pragma once

#include "Window.h"

class Audio
{
private:
	std::string theme = "original";

	float defaultVolume = 50.f;
	float currentVolume = defaultVolume;
	bool muted = false;
	
	std::vector<sf::SoundBuffer> bufferExplosions;
	std::vector<sf::Sound> soundExplosions;
	void loadExplosion(int);
	void loadExplosions();
	std::vector<bool> loadedExplosions = std::vector<bool>(3, false);

	sf::SoundBuffer bufferShoot;
	sf::Sound soundShoot;
	void loadShoot();
	bool loadedShoot = false;

	sf::SoundBuffer bufferRevive;
	sf::Sound soundRevive;
	void loadRevive();
	bool loadedRevive = false;

	sf::SoundBuffer bufferGameStart;
	sf::Sound soundGameStart;
	void loadGameStart();
	bool loadedGameStart = false;

	sf::SoundBuffer bufferGameOver;
	sf::Sound soundGameOver;
	void loadGameOver();
	bool loadedGameOver = false;

	sf::SoundBuffer bufferLifeUp;
	sf::Sound soundLifeUp;
	void loadLifeUp();
	bool loadedLifeUp = false;

	void load();

	sf::RectangleShape volumeBarForeground;
	sf::RectangleShape volumeBarBackground;
	void initShapes();
	void drawVolume();
	void drawMute();

public:
	Audio();
	~Audio();

	void playExplosion(int);
	void playShoot();
	void playRevive();
	void playGameStart();
	void playGameOver();
	void playLifeUp();

	void changeVolume(float);
	void increaseVolume(float);
	void decreaseVolume(float);
	void toggleMute();

	void draw();
};
