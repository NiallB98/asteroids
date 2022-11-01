#include "MenuControlHint.h"

MenuControlHint::MenuControlHint()
{
	initText();
}

MenuControlHint::MenuControlHint(sf::Vector2f windowDims)
{
	updateWindowDimensions(windowDims);
	initText();
}

MenuControlHint::~MenuControlHint()
{

}

sf::Vector2f MenuControlHint::getPos()
{
	return sf::Vector2f(relPos.x + windowDimensions.x / 2.f, relPos.y + windowDimensions.y / 2.f);
}

void MenuControlHint::initText()
{
	txt::initText(font, text, characterSize, getPos(), colour);
	updateText();
}

void MenuControlHint::updateText()
{
	text.setString(controlHintString);
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f));
	text.setPosition(getPos());
}

void MenuControlHint::updateWindowDimensions(sf::Vector2f windowDims)
{
	windowDimensions = windowDims;
}

void MenuControlHint::draw(Window& window)
{
	window.draw(text);
}
