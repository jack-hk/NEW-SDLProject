#include "objects/Visible.h"

Visible::Visible(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture) : texture(texture), Collidable(rect, isMovable, tag)
{
    if (texture == nullptr)
    {
        std::cerr << "Failed to intialize texture: " << this << std::endl;
    }
}

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