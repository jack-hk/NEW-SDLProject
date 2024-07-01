#pragma once
#include <iostream>
#include <SDL.h>

class GraphicsManager
{
public:
	bool initialize(const char* title, const int width, const int height, int r, int g, int b, int a);
	void update();
	void quit();

	inline SDL_Renderer* getRenderer() const { return renderer; }
	inline SDL_Window* getWindow() const { return window; }
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
