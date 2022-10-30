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
	score += asteroidSizeScores[size-1];

	updateText();
}

void Score::ufoHit()
{
	score += ufoScore;

	updateText();
}

void Score::cometHit()
{
	score += cometScore;

	updateText();
}

// Drawing
void Score::initText()
{
	if (!font.loadFromFile("font/VectorBattle.ttf"))
	{
		// error...
	}
	
	text.setFont(font);
	text.setCharacterSize(characterSize);
	text.setPosition(pos);
	text.setFillColor(colour);

	updateText();
}

void Score::updateText()
{
	text.setString(std::to_string(score));
}

void Score::draw(Window& window)
{
	window.draw(text);
}
