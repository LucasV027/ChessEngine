#include "ChessGame.h"

ChessGame::ChessGame() : board{{ChessPiece::BRook, ChessPiece::BKnight, ChessPiece::BBishop, ChessPiece::BQueen, ChessPiece::BKing, ChessPiece::BBishop, ChessPiece::BKnight, ChessPiece::BRook},
                               {ChessPiece::BPawn, ChessPiece::BPawn, ChessPiece::BPawn, ChessPiece::BPawn, ChessPiece::BPawn, ChessPiece::BPawn, ChessPiece::BPawn, ChessPiece::BPawn},
                               {ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None},
                               {ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None},
                               {ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None},
                               {ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None, ChessPiece::None},
                               {ChessPiece::WPawn, ChessPiece::WPawn, ChessPiece::WPawn, ChessPiece::WPawn, ChessPiece::WPawn, ChessPiece::WPawn, ChessPiece::WPawn, ChessPiece::WPawn},
                               {ChessPiece::WRook, ChessPiece::WKnight, ChessPiece::WBishop, ChessPiece::WQueen, ChessPiece::WKing, ChessPiece::WBishop, ChessPiece::WKnight, ChessPiece::WRook}}
{
}

ChessPiece ChessGame::getInBoard(int y, int x) const
{
    return board[y][x];
}

void ChessGame::display() const
{
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            std::cout << std::setfill('0') << std::setw(2) << (int)board[y][x] << " ";
        }
        std::cout << "\n";
    }
}
