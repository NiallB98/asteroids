#include "Lives.h"

#include "Score.h"
#include "Audio.h"

Lives::Lives()
{
	initText();
}

Lives::~Lives()
{

}

int Lives::getLives()
{
	return lives;
}

void Lives::refresh()
{
	lives = startingLives;
	updateText();
}

void Lives::loseOne()
{
	if (lives > 0)
	{
		lives--;
		updateText();
	}
}

void Lives::addOne(Audio& audio)
{
	if (lives < maxLives)
	{
		lives++;
		updateText();

		audio.playLifeUp();
	}
}

// Drawing
void Lives::initText()
{
	txt::initText(font, text, characterSize, pos, colour);
	updateText();
}

void Lives::updateText()
{
	text.setString("Lives: " + std::to_string(getLives()));
}

void Lives::initDeathScreenSettings()
{
	showText = false;
}

void Lives::draw(Window& window)
{
	if (showText)
		window.draw(text);
}

void Lives::bonusLivesCheck(Score& score, Audio& audio)
{
	if (score.getScore() >= newLivesThresholdMultiplier * newLivesThreshold)
	{
		addOne(audio);
		newLivesThresholdMultiplier++;
	}
}

void Lives::update(Score& score, Audio& audio)
{
	bonusLivesCheck(score, audio);
}
