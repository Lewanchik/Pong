#pragma once
#include "TextureGetter.hpp"

class GameObject
{
public:
	GameObject(const char *name, SDL_Renderer *renderer, int width, int height);
	

	void	freeAll();

	void	update();
	void	render();

	void	setX(int x);
	void	setY(int y);
	int		getX() const;
	int		getY() const;

private:
	int __x;
	int __y;

	SDL_Texture*	texture;
	SDL_Rect		rect;
	SDL_Renderer*	renderer;
};

