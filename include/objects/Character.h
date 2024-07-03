#pragma once
#include "Visible.h"

class Character : public Visible
{
public:
	Character(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture, int hitPoints);

	inline int getHitPoints() { return hitPoints; }
	inline void damageHitPoints(int damage) { hitPoints -= damage; }

protected:
	int hitPoints;
};