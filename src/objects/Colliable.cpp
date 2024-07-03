#include "objects\Collidable.h"

Collidable::Collidable(SDL_Rect rect, bool isMovable, const char* tag) : GameObject(rect), isMovable(isMovable), touchingCollider(nullptr), tag(tag) {}

Collidable::~Collidable()
{
	touchingCollider = nullptr;
}