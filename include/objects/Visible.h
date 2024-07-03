#pragma once
#include "Collidable.h"
#include "GraphicsManager.h"

class Visible : public Collidable
{
public:
	Visible(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture);
	~Visible();

	void draw(SDL_Renderer* renderer);

private:
	SDL_Texture* texture;
};