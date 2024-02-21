#pragma once

#include <string>
#include <iostream>
#include <iomanip>

enum class ChessPiece
{
    None = -1,

    WPawn = 0,
    WRook = 1,
    WKnight = 2,
    WBishop = 3,
    WQueen = 4,
    WKing = 5,

    BPawn = 6,
    BRook = 7,
    BKnight = 8,
    BBishop = 9,
    BQueen = 10,
    BKing = 11
};

class ChessGame
{
public:
    ChessGame();
    ChessGame(std::string FEN);

    ChessPiece getInBoard(int y, int x) const;

    void display() const;

private:
    ChessPiece board[8][8];
};
