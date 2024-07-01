#include <SDL.h>
#include "Game.h"
#include "GraphicsManager.h"
#include "GameObject.h"

// Project Details
// ===============
// Standard Version: C++20

int main(int argc, char* args[])
{
	GameObject* go1 = new GameObject(Vector2D(1, 2), 20);
	Game& game = Game::getInstance();
	if (!game.initialize()) return -1;
	game.run();
	game.quit();
	return 0;
}