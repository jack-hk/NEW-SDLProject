#include <SDL.h>
#include "Game.h"
#include "GraphicsManager.h"

// Project Details
// ===============
// Standard Version: C++20

int main(int argc, char* args[])
{
	Game& game = Game::getInstance();
	GraphicsManager graphicsWindow;

	if (!game.initialize()) return -1;

	game.run();

	game.quit();
	return 0;
}