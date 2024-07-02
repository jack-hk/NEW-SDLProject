#pragma once
#include "Visible.h"

class Character : public Visible
{
public:
	Character(SDL_Rect rect, bool isMovable, SDL_Texture* texture, int hitPoints);

	inline int getHitPoints() { return hitPoints; }

private:
	int hitPoints;
};