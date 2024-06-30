#include <SDL.h>
#include <iostream>

// Project Details
// ===============
// Standard Version: C++20
// Style Convention: Google (https://google.github.io/styleguide/cppguide.html)

#include "Game.h"

const int WINDOWSIZE_WIDTH = 600;
const int WINDOWSIZE_HEIGHT = 600;

int main(int argc, char* args[])
{
	Game& game = Game::getInstance();
	if (!game.initialize()) return -1;

	SDL_Window* window = SDL_CreateWindow("NEW Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) std::cout << "Failed to create window! SDL_Error: " << SDL_GetError << std::endl;
	else
	{
		SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		SDL_UpdateWindowSurface(window);

		//Hack to get window to stay up!
		SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}