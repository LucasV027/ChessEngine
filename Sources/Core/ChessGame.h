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

struct MoveInfo
{
    char move[2]; // origin and destination squares (0 - 63)
    bool side;    // side moving LIGHT=0 or DARK=1

    char piece;          // king=0, queens=2,rooks=4,bishops=6,pawns=8
    char captured_piece; // king=0, queens=2,rooks=4,bishops=6,pawns=8
    bool capture;        // is this move a capture

    bool canCastle_off[4];
    bool isCastle[4];

    bool passant_capture; // is this move a capture using en passant
    char enPassant;       // if the pawn is pushed two places, set en passant square, along with the square the pawn is on for capture porpoises

    bool promotion;
    char promotion_piece;
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
