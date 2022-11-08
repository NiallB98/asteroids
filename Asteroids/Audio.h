#pragma once

#include "Window.h"
#include "AudioBar.h"

class Audio
{
private:
	std::string theme = "custom";

	float defaultVolume = 50.f;
	float currentVolume = defaultVolume;
	bool muted = false;
	
	int numExplosionTypes = 4;
	std::vector<sf::SoundBuffer> bufferExplosions = std::vector<sf::SoundBuffer>(numExplosionTypes);
	std::vector<sf::Sound> soundExplosions = std::vector<sf::Sound>(numExplosionTypes);
	void loadExplosion(int);
	void loadExplosions();
	std::vector<bool> loadedExplosions = std::vector<bool>(numExplosionTypes, false);

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

	std::vector<AudioBar> audioBars = std::vector<AudioBar>(0);
	bool showNewAudioBar = false;
	void showAudioBar(sf::Vector2f, sf::Clock&);

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

	void draw(Window&);

	void update(sf::Vector2f, sf::Clock&);
	void postUpdate();
};
