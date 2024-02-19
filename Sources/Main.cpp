#include <iostream>

#include "Application/Application.h"

int main(int argc, char *argv[])
{
    Application ChessEngine("ChessEngine", 800, 800, 60);
    ChessEngine.Run();
}