#include "objects/Collectible.h"

Collectible::Collectible(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture) : Visible(rect, isMovable, tag, texture) 
{
}