#include "GraphicsManager.h"

bool GraphicsManager::initialize(const char* title, const int width, const int height, int r, int g, int b, int a)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize SDL Video! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else std::cout << "Succesfully initialized SDL Video..." << std::endl;

	if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		std::cout << "Failed to initialize SDL Video! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	std::cout << "Succesfully initialized SDL_Image..." << std::endl;

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

SDL_Texture* GraphicsManager::loadTexture(const char* filename)
{
	SDL_Surface* image = IMG_Load(filename);
	if (image == nullptr)
	{
		std::cout << "Failed to IMG_Load! SDL Error: " << IMG_GetError() << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	if (texture == nullptr)
	{
		std::cerr << "Failed to SDL_CreateTextureFromSurface! SDL Error: " << SDL_GetError() << std::endl;
	}

	std::cout << "Loaded image: " << filename << std::endl;
	return texture;
}

void GraphicsManager::drawTexture(SDL_Rect dstRect, SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);
}

void GraphicsManager::quit()
{
	SDL_DestroyRenderer(renderer);
	std::cout << "Destroyed Renderer..." << std::endl;

	SDL_DestroyWindow(window);
	std::cout << "Destroyed Window..." << std::endl;
}