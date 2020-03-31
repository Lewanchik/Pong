#include "Game.hpp"

Game::Game()
{
	initGame();
}

void Game::initGame()
{
	ball = Ball(10, 7); 
	platforms[0] = Platform(0, 3);
	platforms[1] = Platform(0, 3);
	window.initWindow();
	window.addGameObject("Ball", "Ball9.png", BALL_WIDTH, BALL_HEIGHT);
	window.addGameObject("Platform", "platform.png", PLATFORM_W, PLATFORM_H);
	window.addGameObject("Bot", "platform.png", PLATFORM_W, PLATFORM_H);
	delay = 20;
	quit = 0;
	event = 0;
}

int botAlgorithm(const GameObject& ballObject, const GameObject& botObject)
{
	int yBall = ballObject.getY() + BALL_HEIGHT / 2;
	int yBot = botObject.getY() + PLATFORM_H / 2;

	if (yBot > yBall)
		return up;
	return down;
}

void Game::platformMove(GameObject &platform, int platformNumber, int event)
{
	Point point;

	platforms[0].setDirection(event);
	point = Calculation::PlatformCalculation(platforms[0]);
	if (platform.getY() - point.y > 1 && platform.getY() - point.y + PLATFORM_H < WINDOW_H)
	{
		platform.setX(platform.getX() + point.x);
		platform.setY(platform.getY() - point.y);
	}
}

void Game::gameLoop()
{
	int i = 0;
	GameObject& ballObject = window.findGameObjectByName("Ball");
	GameObject& platformObject = window.findGameObjectByName("Platform");
	GameObject& botObject = window.findGameObjectByName("Bot");
	ballObject.setX(WINDOW_W / 2 - BALL_WIDTH);
	ballObject.setY(200);
	botObject.setX(700);
	botObject.setY(WINDOW_H / 2 - PLATFORM_H / 2);
	platformObject.setX(100);
	platformObject.setY(WINDOW_H / 2 - PLATFORM_H / 2);

	while (!quit)
	{
		event = window.handleEvents();
		if (event == escape)
		{
			quit = 1;
			break;
		}
		if (event)
			platformMove(platformObject, 0, event);

		platformMove(botObject, 1, botAlgorithm(ballObject, botObject));
		checkColision(ballObject, platformObject, botObject);
		window.update();
		window.render();
		SDL_Delay(delay);
		i++;
	} 
}

void Game::checkColision(GameObject& ball, const GameObject& platform, const GameObject &bot)
{
	Point point = {0, 0};
	int tmp;
	int x;
	int y;

	nullmap();
	setPlatformOnMap(platform, 'P');
	setPlatformOnMap(bot, 'B');
	x = ball.getX();
	y = ball.getY();
	if (x <= 0 || x >= WINDOW_W)
	{
		if (x <= 0)
		{
			window.getScore().addPointY();
			this->ball.setDirection(0);
		}
		else
		{
			window.getScore().addPointX();
			this->ball.setDirection(180);
		}
		gameLoop();
		return ;
	}
	tmp = setBallOnMap(ball);
	if (tmp == 1)
		point = Calculation::BallCalculation(this->ball, x, y, this->platforms[0]);
	else if (tmp == 2)
		point = Calculation::BallCalculation(this->ball, x, y, this->platforms[1]);
	else
		point = Calculation::BallCalculation(this->ball, x, y);
	ball.setX(ball.getX() - point.x);
	ball.setY(ball.getY() + point.y);
}


int Game::setBallOnMap(GameObject& ball)
{
	int x = ball.getX();
	int y = ball.getY();
	bool label = 0;

	try
	{
		for (int i = 0; i < BALL_HEIGHT; i++)
		{
			for (int j = 0; j < BALL_WIDTH; j++)
			{
				if (map[i + y][j + x] != '0')
				{
					if (map[i + y][j + x] == 'P')
						return 1;
					if (map[i + y][j + x] == 'B')
						return 2;
				}
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

void Game::setPlatformOnMap(const GameObject& platform, char sign)
{
	int x = platform.getX();
	int y = platform.getY();


	for (int i = 0; i < PLATFORM_H; i++)
	{
		for (int j = 0; j < PLATFORM_W; j++)
		{
			map[i + y][j + x] = sign;
		}
	}
}

void Game::nullmap()
{
	for (int i = 0; i < WINDOW_H; i++)
	{
		for (int j = 0; j < WINDOW_W; j++)
		{
			map[i][j] = '0';
		}
	}
}