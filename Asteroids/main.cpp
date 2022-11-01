#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")									// Hide console when running compiled version
#include "Game.h"

int main()
{
	srand(time(NULL));																				// Setting random seed

	Game game;

	while (game.isRunning())
	{
		game.update();
		game.postUpdate();
		game.render();
	}
	
	return 0;
}
