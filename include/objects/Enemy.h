#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture, int hitPoints);

	void update();
};