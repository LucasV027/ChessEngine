#pragma once

#include <chrono>
#include <iostream>

#include <SDL2/SDL.h>

class Application
{
public:
    Application(const char *windowName, int width, int height, int maxFPS);

    void Run();

    ~Application();

private:
    void handleEvents();

private:
    // Window & parameters
    int windowWidth;
    int windowHeight;
    SDL_Window *window = NULL;
    int maxFPS;
    bool isRunning;
    SDL_Event event;
};