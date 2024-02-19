#pragma once

#include <SDL2/SDL.h>

class Renderer
{
public:
    Renderer();
    ~Renderer();

    bool init(SDL_Window *window);
    void render();

private:
    SDL_Renderer *rRenderer;
};