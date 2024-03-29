#include "Application.h"

Application::Application(const char *windowName, int width, int height, int _maxFPS) : windowWidth(width),
                                                                                       windowHeight(height),
                                                                                       isRunning(true),
                                                                                       maxFPS(_maxFPS),
                                                                                       chessGame(nullptr)

{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return;
    }

    if (!myRenderer.init(window))
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return;
    }

    const int SCREEN_TICKS_PER_FRAME = 1000 / maxFPS;
    int frame = 0;

    chessGame = new ChessGame();
    myRenderer.linkChessGame(chessGame);
}

Application::~Application()
{
    std::cout << "Closing..." << std::endl;
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Application::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        // WINDOW EVENTS //
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_RESIZED)
            {
            }
            break;

        // KEYBOARD EVENTS //
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_q:
                isRunning = false;
                break;

            default:
                break;
            }

        // MOUSE EVENTS //
        case SDL_MOUSEBUTTONDOWN:

            break;

        default:
            break;
        }
    }
}

void Application::Run()
{
    // Delta time
    Uint32 lastUpdate = SDL_GetTicks();

    // Average FPS
    int frameCounter = 0;
    const auto start2 = std::chrono::high_resolution_clock::now();

    while (isRunning)
    {
        Uint64 start = SDL_GetPerformanceCounter();

        handleEvents();
        myRenderer.render();

        Uint64 end = SDL_GetPerformanceCounter();
        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(std::max(0.f, floor(16.666f - elapsedMS)));
        frameCounter++;
    }

    // Average FPS
    const auto end2 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> diff = end2 - start2;
    std::cout << "average FPS : " << frameCounter / diff.count() << std::endl;
}