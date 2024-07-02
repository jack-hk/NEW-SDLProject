#include "objects/Character.h"

Character::Character(SDL_Rect rect, bool isMovable, SDL_Texture* texture, int hitPoints) : Visible(rect, isMovable, texture), hitPoints(hitPoints) {}