#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class GraphicsManager
{
public:
	bool initialize(const char* title, const int width, const int height, int r, int g, int b, int a);
	void quit();
	
	SDL_Texture* loadTexture(const char* filename);
	void drawTexture(SDL_Rect dstRect, SDL_Texture* texture);

	inline void clearRenderer() { SDL_RenderClear(renderer); }
	inline void presentRenderer() { SDL_RenderPresent(renderer); }

	inline SDL_Renderer* getRenderer() const { return renderer; }
	inline SDL_Window* getWindow() const { return window; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
