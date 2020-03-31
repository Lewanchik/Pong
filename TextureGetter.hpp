#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "TextureRect.h"

class TextureGetter
{
public:
	static TextureRect getTextureByName(const char* nameOfTexture, SDL_Renderer* renderer, int width, int height);
};
