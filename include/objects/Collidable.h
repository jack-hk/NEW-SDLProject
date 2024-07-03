#pragma once
#include "GameObject.h"

class Collidable : public GameObject
{
public:
	Collidable(SDL_Rect rect, bool isMovable, const char* tag);
	~Collidable();

	inline void setIsColliding(bool isCollide) { isColliding = isCollide; }
	inline void setTochingCollider(Collidable* collidable) { touchingCollider = collidable; }

	inline bool getIsMovable() { return this->isMovable; }
	inline const char* getTag() { return this->tag; }

protected:
	bool isColliding = false;
	Collidable* touchingCollider;
private:
	const char* tag;
	bool isMovable;
};