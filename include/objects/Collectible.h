#pragma once
#include "Visible.h"

class Collectible : public Visible
{
public:
	Collectible(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture);

	virtual void update() = 0;
};