#pragma once
#include "GameObject.h"

class Collidable : public GameObject
{
public:
	Collidable(SDL_Rect rect);

	void SetIsColliding(bool isCollide) { isColliding = isCollide; }
protected:
	bool isColliding = false;
};