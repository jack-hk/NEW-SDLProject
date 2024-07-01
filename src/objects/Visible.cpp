#include "objects/Visible.h"

Visible::Visible(SDL_Rect rect, SDL_Texture* texture) : texture(texture), Collidable(rect), graphics(nullptr) {}

Visible::~Visible()
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void Visible::draw(SDL_Renderer* renderer)
{
    if (texture)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }
}