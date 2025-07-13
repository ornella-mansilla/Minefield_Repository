#include <iostream>
#include <iomanip>
#include "board_header.h"

namespace BoardUtils
{
    void printBoardPerPlayer(const Board& board, const Player& player)
    {
        // print column headers
        std::cout << "    ";
        for (int x : board.axisX)
        {
            std::cout << (x < 10 ? " " : "") << x << " ";
        }
        std::cout << "\n   ";
        for (size_t i = 0; i < board.axisX.size(); ++i) std::cout << "---";
        std::cout << "\n";

        for (size_t y = 0; y < board.axisY.size(); ++y)
        {
            int displayY = board.axisY[y];
            std::cout << (displayY < 10 ? " " : "") << displayY << "| ";

            for (size_t x = 0; x < board.axisX.size(); ++x)
            {
                // Check if this cell is/has a player's mine
                bool isMineForPlayer = false;
                for (const auto& mine : player.mines)
                {
                    int mineX = mine.cell.getX();
                    int mineY = mine.cell.getY();
                    if (mineX == board.axisX[x] && mineY == board.axisY[y])
                    {
                        isMineForPlayer = true;
                        break;
                    }
                }

                if (isMineForPlayer){
                    std::cout << "*  "; // mine visible to this player
                }
                else{
                    std::cout << board.grid[y][x].getSymbol() << "  "; // actual state of the cell
                }
            }
            std::cout << "\n";
        }
    }
    
}