#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "TextureRect.h"
#include <string>

constexpr auto SIZE = 30;
constexpr auto MESSAGE_W = 40;
constexpr auto MESSAGE_H = 40;
constexpr auto MESSAGE_X = 400;
constexpr auto MESSAGE_Y = 20;


class Score
{
public:
    Score() = default;
    Score(SDL_Renderer *renderer, SDL_Color color);
    
    void    update();
    void    render();
    void    addPointX();
    void    addPointY();

    void    freeAll();

private:
    SDL_Renderer*   renderer;
    TTF_Font*       sans;
    SDL_Color       color;
    Point           score;
    SDL_Surface*    surfaceMessage;
    SDL_Texture*    message;
    SDL_Rect        messageRect;
};
