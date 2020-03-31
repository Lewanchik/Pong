#include "TextureGetter.hpp"

TextureRect TextureGetter::getTextureByName(const char* nameOfTexture, SDL_Renderer* renderer, int width, int height)
{
    SDL_Texture* result = NULL;
    SDL_Rect        targetDimensions;
    TextureRect     textureRect;
    const int       limit = 30;
    SDL_Surface* pSurface = IMG_Load(nameOfTexture);

    if (pSurface == NULL)
        std::cout << "Error image load:" << IMG_GetError();
    else
    {
        targetDimensions.w = width;
        targetDimensions.h = height;
        SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pSurface);
        if (pTexture == NULL)
            std::cout << "Error image load:" << SDL_GetError();
        else
        {
            SDL_SetTextureBlendMode(
                pTexture,
                SDL_BLENDMODE_BLEND);
            result = pTexture;
        }
        SDL_FreeSurface(pSurface);
    }
    textureRect.texture = result;
    textureRect.rect = std::move(targetDimensions);
    return textureRect;
}
