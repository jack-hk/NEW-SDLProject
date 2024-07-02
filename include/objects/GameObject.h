#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "VectorMath.h"

// Serves as a frame for components.
class GameObject
{
public:
	GameObject(SDL_Rect rect);

	inline int getW() { return rect.w; }
	inline int getH() { return rect.h; }
	inline SDL_Rect getBody() { return rect; }
	inline Vector2D getPosition() { return Vector2D(rect.x, rect.y); }
	inline void transform(Vector2D transform) { rect.x = transform.x, rect.y = transform.y; }
protected:
	SDL_Rect rect;
};