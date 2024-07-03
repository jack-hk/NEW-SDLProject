#include "objects/Projectile.h"

Projectile::Projectile(SDL_Rect rect, SDL_Texture* texture, const char* tag, Vector2D direction) : Visible(rect, true, tag, texture ), direction(direction)
{
    
}

void Projectile::update()
{
    transform(Vector2D(rect.x + direction.x, rect.y + direction.y));

    if (isColliding) destroyMe = true;
}