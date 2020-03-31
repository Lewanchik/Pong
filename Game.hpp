#pragma once
#include "Ball.hpp"
#include "Platform.hpp"
#include "TextureRect.h"
#include "Window.hpp"
#include "Calculation.hpp"
#include "Score.hpp"

class Game
{
public:
	Game();
	void	gameLoop();


private:
	void	platformMove(GameObject& platform, int platformNumber, int event);
	void	checkColision(GameObject& ball, const GameObject& platform, const GameObject &bot);
	void	initGame();
	void	setPlatformOnMap(const GameObject& platform, char sign);
	int 	setBallOnMap(GameObject& ball);
	void	nullmap();

	Platform	platforms[2];
	Ball		ball;
	char		map[WINDOW_H][WINDOW_W];
	Window		window;
	int			delay;
	int			quit;
	int			event;
};

