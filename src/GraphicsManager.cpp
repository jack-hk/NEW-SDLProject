#include "GraphicsManager.h"

bool GraphicsManager::initialize(const char* title, const int width, const int height, int r, int g, int b, int a)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize SDL Video! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else std::cout << "Succesfully initialized SDL Video..." << std::endl;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window)
	{
		std::cout << "Failed to create Window! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else std::cout << "Succesfully created Window..." << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cout << "Failed to create Renderer! SDL_Error: " << std::endl;
		SDL_DestroyWindow(window);
		return false;
	}
	else std::cout << "Succesfully created Renderer..." << std::endl;

	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	return true;
}

void GraphicsManager::update()
{
	SDL_RenderClear(renderer);
	SDL_UpdateWindowSurface(window);
	SDL_RenderPresent(renderer);
}

void GraphicsManager::quit()
{
	SDL_DestroyRenderer(renderer);
	std::cout << "Destroyed Renderer..." << std::endl;

	SDL_DestroyWindow(window);
	std::cout << "Destroyed Window..." << std::endl;
}