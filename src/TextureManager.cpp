#include "TextureManager.h"

bool TextureManager::initialize(SDL_Renderer* renderer, bool debugEnabled)
{
    debuggingMode = debugEnabled;
    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        std::cout << "Failed to initialize SDL Video! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "Succesfully initialized SDL_Image..." << std::endl;
}

void TextureManager::quit()
{
    for (auto& texture : textures)
    {
        SDL_DestroyTexture(texture.second);
    }
    std::cout << "Destroyed TextureManager textures..." << std::endl;

    IMG_Quit();
    std::cout << "Quitted SDL_Image..." << std::endl;
}

SDL_Texture* TextureManager::loadTexture(const std::string& filePath)
{
    if (textures.find(filePath) != textures.end())
    {
        return textures[filePath];
    }

    SDL_Surface* tempSurface = IMG_Load(filePath.c_str());
    if (!tempSurface)
    {
        std::cerr << "Failed to IMG_Load! SDL Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (!texture)
    {
        std::cerr << "Failed to SDL_CreateTextureFromSurface! SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    textures[filePath] = texture;

    if (debuggingMode) std::cout << "[TextureManager] Loaded texture: " << filePath << std::endl;
    return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(renderer, texture, &src, &dest);
}
