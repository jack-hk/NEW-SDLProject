#pragma once
#include "Collidable.h"
#include "GraphicsManager.h"

class Visible : public Collidable
{
public:
	Visible(SDL_Rect rect, bool isMovable, SDL_Texture* texture);
	~Visible();

	void draw(SDL_Renderer* renderer);
private:
	GraphicsManager* graphics;
	SDL_Texture* texture;
};