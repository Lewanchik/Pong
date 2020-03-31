#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureRect.h"
#include "TextureGetter.hpp"
#include <map>
#include "GameObject.hpp"
#include "Score.hpp"
#include <string> 

typedef std::pair<std::string, GameObject> gamePair;
typedef std::map<std::string, GameObject> gameObject;

constexpr auto WINDOW_W = 800;
constexpr auto WINDOW_H = 600;
constexpr auto BALL_WIDTH = 32;
constexpr auto BALL_HEIGHT = 32;
constexpr auto PLATFORM_W = 8;
constexpr auto PLATFORM_H = 128;

class Window
{
public:
	Window() = default;
	~Window();

	void		initWindow();
	int			handleEvents();
	void		render();
	void		update();
	void		addGameObject(const std::string &name, const char* path, int width, int height);
	GameObject	&findGameObjectByName(const std::string &name);
	Score		&getScore();
private:
	SDL_Window*		window;
	SDL_Renderer*	renderer;
	gameObject      gameObjects;
	Score			score;
};

