#pragma once
#include "SDL.h"

struct TextureRect
{
	SDL_Texture*	texture;
	SDL_Rect		rect;
};

struct Point
{
	int x;
	int y;
};

struct RGB
{
	int r;
	int g;
	int b;
};

enum Direction
{
	up = 90, down = 270, escape = -1
};