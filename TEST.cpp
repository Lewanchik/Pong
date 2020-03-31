
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Window.hpp"
#include "Ball.hpp"
#include "Platform.hpp"
#include "Calculation.hpp"
#include "Game.hpp"
#undef main

int main()
{
    Game* game = new Game();
    game->gameLoop();
    delete game;
    return 0;
}
