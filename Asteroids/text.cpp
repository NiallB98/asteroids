#include "text.h"

namespace txt
{
	void loadFontError()
	{

	}
	
	void initText(sf::Font& font, sf::Text& text, int characterSize, sf::Vector2f pos, sf::Color colour)
	{
		if (!font.loadFromFile("font/VectorBattle.ttf"))
		{
			loadFontError();
		}

		text.setFont(font);
		text.setCharacterSize(characterSize);
		text.setPosition(pos);
		text.setFillColor(colour);
	}
}
