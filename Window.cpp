#include "Window.hpp"

void Window::initWindow()
{
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    score = Score(renderer, { 255, 0, 0, 255 });
}

Window::~Window()
{
    gameObject::iterator it = gameObjects.begin();

    score.freeAll();
    for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
        it->second.freeAll();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Window::handleEvents()
{
    SDL_Event event;

    SDL_PollEvent(&event);

    Uint8 *keystates = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));
    if (event.type == SDL_KEYDOWN)
        keystates[event.key.keysym.scancode] = true;
    else if (event.type == SDL_KEYUP)
    {
        keystates[event.key.keysym.scancode] = false;
    }
    if (keystates[SDL_SCANCODE_UP])
    {
        return up;
    }
    else if (keystates[SDL_SCANCODE_DOWN])
    {
        return down;
    }
    else if (keystates[SDL_SCANCODE_ESCAPE])
    {
        return escape;
    }
    return 0;
}

void Window::update()
{
    gameObject::iterator it = gameObjects.begin();

    for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
        it->second.update();
    score.update();
}

GameObject &Window::findGameObjectByName(const std::string& name)
{
    gameObject::iterator it = gameObjects.begin();

    for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
    {
        if (it->first == name)
            return it->second;
    }
    throw std::logic_error("Can not find your object");
}

void Window::render()
{
    gameObject::iterator it = gameObjects.begin();

    SDL_RenderClear(renderer);
    for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
        it->second.render();
    score.render();
    SDL_RenderPresent(renderer);
}

void Window::addGameObject(const std::string& name, const char* path, int width, int height)
{
    gameObjects.insert(gamePair(name, GameObject(path, renderer, width, height)));
}


Score &Window::getScore()
{
    return score;
}
