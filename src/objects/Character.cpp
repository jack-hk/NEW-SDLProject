#include "objects/Character.h"

Character::Character(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture, int hitPoints) : Visible(rect, isMovable, tag, texture), hitPoints(hitPoints) {}