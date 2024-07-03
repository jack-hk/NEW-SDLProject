#pragma once
#include "Visible.h"

class Projectile : public Visible
{
public:
	Projectile(SDL_Rect rect, SDL_Texture* texture, const char* tag, Vector2D direction);

	void update();
	bool getDestroyMe() { return this->destroyMe; }
private:
	Vector2D direction;
	bool destroyMe = false;
};