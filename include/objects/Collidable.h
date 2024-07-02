#pragma once
#include "GameObject.h"

class Collidable : public GameObject
{
public:
	Collidable(SDL_Rect rect, bool isMovable);

	inline void setIsColliding(bool isCollide) { isColliding = isCollide; }
	inline bool getIsMovable() { return this->isMovable; }
private:
	bool isColliding;
	bool isMovable;
};