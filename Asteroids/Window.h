#pragma once

#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#define PI 3.14159265
#include <math.h>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Window
{
private:
	bool running = true;
	std::string title = "Asteroids";
	std::string iconPath = "icon/icon/png";

	int width, height, fps;

	void loadConfig();
	void initWindow();
	void loadIcon();

public:
	Window();
	~Window();

	sf::RenderWindow* window;

	bool isRunning();

	sf::Vector2f getDimensions();

	void setFps(int);

	void clear();
	bool pollEvent(sf::Event&);
	void draw(sf::RectangleShape);
	void draw(sf::CircleShape);
	void draw(sf::ConvexShape);
	void draw(sf::VertexArray);
	void display();

	void close();
};
