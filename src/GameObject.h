#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "CommonMath.h"

// Serves as a frame for components.
class GameObject
{
public:
	GameObject(Vector2D go_position, int go_size);

	inline Vector2D getPosition() { return position; }
	inline int getSize() { return size; }
	inline void transform(Vector2D newPosition) { position = newPosition; }
private:
	Vector2D position = Vector2D(0, 0);
	int size = 32;
};