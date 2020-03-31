#include "Score.hpp"

Score::Score(SDL_Renderer* renderer, SDL_Color color)
{
	TTF_Init();
	sans = TTF_OpenFont("arial.ttf", SIZE);
	this->color = color;
	this->renderer = renderer;
	messageRect.w = MESSAGE_W;
	messageRect.h = MESSAGE_H;
	messageRect.x = MESSAGE_X;
	messageRect.y = MESSAGE_Y;
	score.x = 0;
	score.y = 0;
}

void Score::freeAll()
{
	SDL_DestroyTexture(message);
	SDL_FreeSurface(surfaceMessage);
	TTF_CloseFont(sans);
	TTF_Quit();
}

void Score::addPointX()
{
	score.x++;
}

void Score::addPointY()
{
	score.y++;
}

void Score::update()
{
	surfaceMessage = TTF_RenderText_Solid(sans, (std::to_string(score.x) + "  " + std::to_string(score.y)).c_str(), color);
	message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
}

void Score::render()
{
	SDL_RenderCopy(renderer, message, NULL, &messageRect);
}
