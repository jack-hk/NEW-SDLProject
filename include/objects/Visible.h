#pragma once
#include "Collidable.h"
#include "GraphicsManager.h"

class Visible : public Collidable
{
public:
	Visible(SDL_Rect rect, SDL_Texture* texture);
	~Visible();

	void draw(SDL_Renderer* renderer);
protected:
	GraphicsManager* graphics;
	SDL_Texture* texture;
};