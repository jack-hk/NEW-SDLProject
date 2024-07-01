#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
    bool initialize(SDL_Renderer* renderer, bool debugEnabled);
    void quit();

    SDL_Texture* loadTexture(const std::string& filePath);
    void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);

private:
    bool debuggingMode = false;
    SDL_Renderer* renderer;
    std::unordered_map<std::string, SDL_Texture*> textures;
};