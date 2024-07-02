#include "objects/Projectile.h"

Projectile::Projectile(SDL_Rect rect, SDL_Texture* texture, Vector2D direction) : Visible(rect, true, texture), direction(direction)
{
}

void Projectile::update()
{
    transform(Vector2D(rect.x + direction.x, rect.y + direction.y));
}