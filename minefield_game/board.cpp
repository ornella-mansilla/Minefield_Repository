#include <iostream>
#include "board.h"

namespace BoardUtils
{

    void printColumnHeaders(Board const& board)
    {
        std::cout << "    ";
        for (int x : board.axisX)
        {
            std::cout << (x < 10 ? " " : "") << x << " ";
        }
        std::cout << '\n';

        std::cout << "   ";
        for (size_t i = 0; i < board.axisX.size(); ++i)
        {
            std::cout << "---";
        }
        std::cout << '\n';
    }

    bool isMineVisibleForPlayer(Board const& board, Player const& player, size_t x, size_t y)
    {
        for (Mine const& mine : player.mines)
        {
            int mineX = mine.location.x;
            int mineY = mine.location.y;
            if (mineX == board.axisX[x] && mineY == board.axisY[y])
            {
                return true;
            }
        }
        return false;
    }

    void printRow(Board const& board, Player const& player, size_t y)
    {
        int displayY = board.axisY[y];
        std::cout << (displayY < 10 ? " " : "") << displayY << "| ";

        for (size_t x = 0; x < board.axisX.size(); ++x)
        {
            if (isMineVisibleForPlayer(board, player, x, y))
            {
                std::cout << "*  ";
            }
            else
            {
                std::cout << board.grid[y][x].getCellSymbol() << "  ";
            }
        }
        std::cout << '\n';
    }

    void printBoardPerPlayer(Board const& board, Player const& player)
    {
        printColumnHeaders(board);
        for (size_t y = 0; y < board.axisY.size(); ++y)
        {
            printRow(board, player, y);
        }
    }

}