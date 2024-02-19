#include "../Application/Renderer.h"

Renderer::Renderer() : rRenderer(nullptr) {}

bool Renderer::init(SDL_Window *window)
{
    rRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!rRenderer)
    {
        return false;
    }

    return true;
}

void Renderer::render()
{
    SDL_SetRenderDrawColor(rRenderer, 0, 200, 45, 255);
    SDL_RenderClear(rRenderer);
    SDL_RenderPresent(rRenderer);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(rRenderer);
}
