#include "objects/NonMovable.h"

NonMovable::NonMovable(SDL_Rect rect, SDL_Texture* texture) : Visible(rect, texture) {}

NonMovable::~NonMovable()
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}