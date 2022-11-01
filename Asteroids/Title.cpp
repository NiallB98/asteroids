#include "Title.h"

Title::Title()
{
	initText();
}

Title::Title(sf::Vector2f windowDims)
{
	updateWindowDimensions(windowDims);
	initText();
}

Title::~Title()
{

}

sf::Vector2f Title::getPos()
{
	return sf::Vector2f(relPos.x + windowDimensions.x / 2.f, relPos.y + windowDimensions.y / 2.f);
}

void Title::initText()
{
	txt::initText(font, text, characterSize, getPos(), colour);
	updateText();
}

void Title::updateText()
{
	text.setString(titleString);
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f));
	text.setPosition(getPos());
}

void Title::updateWindowDimensions(sf::Vector2f windowDims)
{
	windowDimensions = windowDims;
}

void Title::draw(Window& window)
{
	window.draw(text);
}
