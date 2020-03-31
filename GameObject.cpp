#include "GameObject.hpp"
#include "Window.hpp"

GameObject::GameObject(const char* name, SDL_Renderer* renderer, int width, int height)
{
	TextureRect text = TextureGetter::getTextureByName(name, renderer, width, height);
	this->renderer = renderer;
	texture = text.texture;
	rect = text.rect;
}

void GameObject::freeAll()
{
	SDL_DestroyTexture(texture);
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void GameObject::update()
{
	rect.x = __x;
	rect.y = __y;
}

void GameObject::setX(int x)
{
	__x = x;
}

void GameObject::setY(int y)
{
	__y = y;
}

int GameObject::getX() const
{
	return __x;
}

int GameObject::getY() const
{
	return __y;
}
