#include "Score.h"

Score::Score()
{
	initText();
}

Score::~Score()
{

}

int Score::getScore()
{
	return score;
}

void Score::asteroidHit(int size)
{
	if (not scoreLocked)
	{
		score += asteroidSizeScores[size - 1];
		updateText();
	}
}

void Score::ufoHit()
{
	if (not scoreLocked)
	{
		score += ufoScore;
		updateText();
	}
}

void Score::cometHit()
{
	if (not scoreLocked)
	{
		score += cometScore;
		updateText();
	}
}

// Drawing
void Score::initText()
{
	txt::initText(font, text, characterSize, pos, colour);
	updateText();
}

void Score::updateText()
{
	if (not textLocked)
		text.setString(std::to_string(score));
}

void Score::initDeathScreenSettings(sf::Vector2f windowDims)
{
	text.setString("Final\nScore:\n" + std::to_string(score));
	text.setCharacterSize(deathScreenCharacterSize);
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2,text.getLocalBounds().height / 2));
	text.setPosition(sf::Vector2f(deathScreenPosRelToCentre.x + windowDims.x / 2.f,
		deathScreenPosRelToCentre.y + windowDims.y / 2.f));
	textLocked = true;
	scoreLocked = true;
}

void Score::draw(Window& window)
{
	window.draw(text);
}
