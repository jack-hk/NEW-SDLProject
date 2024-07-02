#pragma once
#include "Visible.h"

class Projectile : public Visible
{
public:
	Projectile(SDL_Rect rect, SDL_Texture* texture, Vector2D direction);

	void update();
private:
	Vector2D direction;
};