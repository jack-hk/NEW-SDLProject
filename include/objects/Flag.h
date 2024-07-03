#pragma once
#include "Collectible.h"

class Flag : public Collectible
{
public:
	Flag(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture);

	void update();
	bool getCollected() { return isCollected; }
private:
	bool isCollected = false;
};