#include <iostream>
#include <iomanip>
#include "board_header.h"

namespace BoardUtils
{
    /*void printBoardPerPlayer(Board const& board, Player const& player)
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
    }*/
    // void printColumnHeaders(const Board &board)
    // {
    //     std::cout << "    ";
    //     for (int x : board.axisX)
    //     {
    //         std::cout << (x < 10 ? " " : "") << x << " ";
    //     }
    //     std::cout << "\n   ";
    //     for (size_t i = 0; i < board.axisX.size(); ++i)
    //     {
    //         std::cout << "---";
    //     }
    //     std::cout << "\n";
    // }

    // bool isMineVisibleForPlayer(const Board &board, const Player &player, size_t x, size_t y)
    // {
    //     for (const auto &mine : player.mines)
    //     {
    //         int mineX = mine.location.getX();
    //         int mineY = mine.location.getY();
    //         if (mineX == board.axisX[x] && mineY == board.axisY[y])
    //         {
    //             return true; // Found a mine for the player
    //         }
    //     }
    //     return false; // No mine found for the player
    // }

    // void printRow(const Board &board, const Player &player, size_t y)
    // {
    //     int displayY = board.axisY[y];
    //     std::cout << (displayY < 10 ? " " : "") << displayY << "| ";

    //     for (size_t x = 0; x < board.axisX.size(); ++x)
    //     {
    //         if (isMineVisibleForPlayer(board, player, x, y))
    //         {
    //             std::cout << "*  "; // mine visible to this player
    //         }
    //         else
    //         {
    //             std::cout << board.grid[y][x].getSymbol() << "  "; // actual state of the cell
    //         }
    //     }
    //     std::cout << "\n";
    // }

    // void printBoardPerPlayer(const Board &board, const Player &player)
    // {
    //     printColumnHeaders(board); // 1. print the column headers

    //     for (size_t y = 0; y < board.axisY.size(); ++y)
    //     {
    //         printRow(board, player, y); // 2. print each row
    //     }
    // }

    // helper functions to print the board for a specific player

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
            int mineX = mine.location.getX();
            int mineY = mine.location.getY();
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
                std::cout << board.grid[y][x].getSymbol() << "  ";
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