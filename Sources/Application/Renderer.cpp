#include "../Application/Renderer.h"

Renderer::Renderer() : rRenderer(nullptr), police(nullptr), cGame(nullptr) {}

bool Renderer::init(SDL_Window *window)
{
    // Renderer initialization
    rRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!rRenderer)
    {
        std::cout << "Renderer could not be created! SDL Error : " << SDL_GetError() << std::endl;
        return false;
    }

    // Textures
    std::string piecesTexturePath = "../Assets/Textures/chess.png";
    chessPiecesTexture = IMG_LoadTexture(rRenderer, piecesTexturePath.c_str());

    if (!chessPiecesTexture)
    {
        std::cout << "The renderer could not load " << piecesTexturePath << " ! SDL_Error : " << SDL_GetError() << std::endl;
        return false;
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

    // Font
    if (TTF_Init() == -1)
    {
        std::cout << "TTF_Init initialization error : " << TTF_GetError();
        return false;
    }

    std::string fontPath = "../Assets/Fonts/Roboto/Roboto-Black.ttf";
    police = TTF_OpenFont(fontPath.c_str(), 10);
    if (!police)
    {
        std::cout << "The renderer could not load " << fontPath << " ! SDL_Error : " << SDL_GetError() << std::endl;
        return false;
    }

    //
    return true;
}

void Renderer::linkChessGame(ChessGame *cGame) { this->cGame = cGame; }

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

void Renderer::drawPieces()
{
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            ChessPiece piece = this->cGame->getInBoard(y, x);
            SDL_Rect sprite;

            switch (piece)
            {
            case ChessPiece::None:
                continue;

            case ChessPiece::WPawn:
            case ChessPiece::BPawn:
                sprite = pawnSprite;
                break;
            case ChessPiece::WRook:
            case ChessPiece::BRook:
                sprite = rookSprite;
                break;
            case ChessPiece::WKnight:
            case ChessPiece::BKnight:
                sprite = knightSprite;
                break;
            case ChessPiece::WBishop:
            case ChessPiece::BBishop:
                sprite = bishopSprite;
                break;
            case ChessPiece::WQueen:
            case ChessPiece::BQueen:
                sprite = queenSprite;
                break;
            case ChessPiece::WKing:
            case ChessPiece::BKing:
                sprite = kingSprite;
                break;
            }

            bool white = (int)piece <= 5;
            sprite.y = (white ? 128 : 0);
            SDL_Rect rect{x * 100, y * 100, 100, 100};
            SDL_RenderCopy(rRenderer, chessPiecesTexture, &sprite, &rect);
        }
    }
}

Renderer::~Renderer()
{
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_DestroyRenderer(rRenderer);
}
