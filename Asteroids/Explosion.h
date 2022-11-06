#pragma once

#include "Window.h"

class Audio;

class Explosion
{
private:
	sf::Vector2f pos = sf::Vector2f(0.f, 0.f);
	void setPos(sf::Vector2f);

	bool alive = true;
	float createdAtSeconds = 0.f;
	float lifespanSeconds = 1.f;

	int size = 3;

	float minSpeedFactor = 0.001f;
	float maxSpeedFactor = 0.005f;

	float particleSize = 2.f;

	int numParticles = 30;
	std::vector<sf::VertexArray> particles = std::vector<sf::VertexArray>(numParticles,
		sf::VertexArray(sf::LinesStrip, 2));

	std::vector<sf::Vector2f> shapePositions = std::vector<sf::Vector2f>(numParticles, sf::Vector2f(0.f, 0.f));
	std::vector<float> shapeRotations = std::vector<float>(numParticles, 0.f);
	std::vector<sf::Vector2f> shapeVelocities = std::vector<sf::Vector2f>(numParticles, sf::Vector2f(0.f, 0.f));

	void initShapes();
	void initShapeVelocities();

	void moveShapes();
	void updateVertexArrays();

public:
	Explosion();
	Explosion(Audio&, sf::Vector2f, int, sf::Clock&);
	~Explosion();

	bool hasExpired();

	void update();
	void postUpdate(sf::Clock&);

	void draw(Window&);
};
