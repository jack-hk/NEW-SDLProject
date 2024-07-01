#pragma once
#include <iostream>
#include <SDL.h>
#include "GraphicsManager.h"
#include "InputManager.h"

// Singleton Class
class Game
{
public:
	static Game& getInstance()
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
	Game() : graphics() {}

	const const char* WINDOW_TITLE = "Adventure Maze";
	const int WINDOWSIZE_WIDTH = 600;
	const int WINDOWSIZE_HEIGHT = 600;
	const int WINDOWCOLOR_RED = 100;
	const int WINDOWCOLOR_GREEN = 100;
	const int WINDOWCOLOR_BLUE = 160;
	const int WINDOWCOLOR_ALPHA = SDL_ALPHA_OPAQUE;

	bool isRunning = false;

	GraphicsManager graphics;
	InputManager input;
};