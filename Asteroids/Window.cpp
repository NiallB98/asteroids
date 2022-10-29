#include "Window.h"


Window::Window()
{
	loadConfig();
	initWindow();
}

Window::~Window()
{
	delete window;
}

sf::Vector2f Window::getDimensions()
{
	return sf::Vector2f(width, height);
}

void Window::loadConfig()
{
	width = 720;
	height = 720;
	fps = 60;																						// FPS Target
}

void Window::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	setFps(fps);
}

void Window::setFps(int fps_limit)
{
	fps = fps_limit;
	window->setFramerateLimit(fps_limit);
}

void Window::loadIcon()
{
	sf::Image icon;																					// Setting Game Icon
	if (!icon.loadFromFile(iconPath))														        //
		exit(EXIT_FAILURE);																			//
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());						//
}

void Window::clear()
{
	window->clear();
}

bool Window::pollEvent(sf::Event& event)
{
	return window->pollEvent(event);
}

void Window::draw(sf::RectangleShape rect)
{
	window->draw(rect);
}

void Window::draw(sf::CircleShape circ)
{
	window->draw(circ);
}

void Window::draw(sf::ConvexShape conv)
{
	window->draw(conv);
}

void Window::draw(sf::VertexArray vertArr)
{
	window->draw(vertArr);
}

void Window::display()
{
	window->display();
}

bool Window::isRunning()
{
	return running;
}

void Window::close()
{
	running = false;
}
