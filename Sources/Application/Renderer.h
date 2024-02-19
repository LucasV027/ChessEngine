#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer
{
public:
    Renderer();
    ~Renderer();

    bool init(SDL_Window *window);
    void render();

private:
    void drawBackground();
    void drawPieces();

private:
    SDL_Renderer *rRenderer;

    SDL_Texture *chessPiecesTexture;

    SDL_Rect pawnSprite;
    SDL_Rect rookSprite;
    SDL_Rect knightSprite;
    SDL_Rect bishopSprite;
    SDL_Rect queenSprite;
    SDL_Rect kingSprite;
};