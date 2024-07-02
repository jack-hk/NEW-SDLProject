#include "objects\Collidable.h"

Collidable::Collidable(SDL_Rect rect, bool isMovable) : GameObject(rect), isMovable(isMovable) {}