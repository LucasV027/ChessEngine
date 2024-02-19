#include "../Application/Renderer.h"

Renderer::Renderer() : rRenderer(nullptr) {}

bool Renderer::init(SDL_Window *window)
{
    rRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!rRenderer)
    {
        return false;
    }

    // Loading & assinging values for the chess pieces texture
    chessPiecesTexture = IMG_LoadTexture(rRenderer, "../Assets/Textures/chess.png");

    if (!chessPiecesTexture)
    {
        printf("The renderer could not load Assets/Textures/chess.png ! SDL_Error: %s\n", SDL_GetError());
    }

    int chessPiecesTextureWidth, chessPiecesTextureHeight;
    SDL_QueryTexture(chessPiecesTexture, NULL, NULL, &chessPiecesTextureWidth, &chessPiecesTextureHeight);
    int spriteHeight = chessPiecesTextureHeight / 2;
    int spriteWidth = chessPiecesTextureWidth / 6;

    pawnSprite = SDL_Rect{0, 0, spriteWidth, spriteHeight};
    rookSprite = SDL_Rect{spriteWidth * 3, 0, spriteWidth, spriteHeight};
    knightSprite = SDL_Rect{spriteWidth, 0, spriteWidth, spriteHeight};
    bishopSprite = SDL_Rect{spriteWidth * 2, 0, spriteWidth, spriteHeight};
    queenSprite = SDL_Rect{spriteWidth * 4, 0, spriteWidth, spriteHeight};
    kingSprite = SDL_Rect{spriteWidth * 5, 0, spriteWidth, spriteHeight};

    return true;
}

void Renderer::render()
{
    drawBackground();
    drawPieces();

    SDL_RenderPresent(rRenderer);
}

void Renderer::drawBackground()
{
    // Background (Color = green)
    SDL_SetRenderDrawColor(rRenderer, 235, 236, 208, 255);
    SDL_RenderClear(rRenderer);

    // Grid on top of the background (Color = white / beige)
    SDL_SetRenderDrawColor(rRenderer, 119, 149, 86, 25);
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if ((x + y) % 2)
            {
                SDL_Rect rect{x * 100, y * 100, 100, 100};
                SDL_RenderFillRect(rRenderer, &rect);
            }
        }
    }
}

void Renderer::drawPieces() {}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(rRenderer);
}
