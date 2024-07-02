#pragma once
#include "Visible.h"

class NonMovable : public Visible
{
	NonMovable(SDL_Rect rect, SDL_Texture* texture);
	~NonMovable();

};