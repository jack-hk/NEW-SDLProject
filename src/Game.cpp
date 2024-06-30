#pragma once
#include "Game.h"

bool Game::initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Filed to initialize SDL! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}