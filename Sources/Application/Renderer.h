#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

#include "../Core/ChessGame.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    bool init(SDL_Window *window);
    void linkChessGame(ChessGame *cGame);
    void render();

private:
    void drawBackground();
    void drawPieces();

private:
    SDL_Renderer *rRenderer;

    // Textures
    SDL_Texture *chessPiecesTexture;
    SDL_Rect pawnSprite;
    SDL_Rect rookSprite;
    SDL_Rect knightSprite;
    SDL_Rect bishopSprite;
    SDL_Rect queenSprite;
    SDL_Rect kingSprite;

    // Fonts
    TTF_Font *police;

    // Core
    ChessGame *cGame;
};