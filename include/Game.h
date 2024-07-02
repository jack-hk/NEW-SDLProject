#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "GraphicsManager.h"
#include "InputManager.h"
#include "CollisionManager.h"

#include "objects/NonMovable.h"

// Singleton class.
class Level;
class Game
{
public:
	static inline Game& getInstance()
	{
		static Game instance;
		return instance;
	}
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	bool initialize();
	void run();
	void quit();

private:
	Game() : graphics(), input() {}

	const bool DEBUG_MODE = true;

	const char* WINDOW_TITLE = "Adventure Maze";
	const int WINDOWSIZE_WIDTH = 600;
	const int WINDOWSIZE_HEIGHT = 600;
	const int WINDOWCOLOR_RED = 100;
	const int WINDOWCOLOR_GREEN = 100;
	const int WINDOWCOLOR_BLUE = 160;
	const int WINDOWCOLOR_ALPHA = SDL_ALPHA_OPAQUE;

	bool isRunning = false;

	GraphicsManager graphics;
	InputManager input;
	CollisionManager collision;
};