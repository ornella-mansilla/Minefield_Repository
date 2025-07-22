#include <iostream>
#include <vector>
#include "init_header.h"
#include "cell_header.h"
#include "player_header.h"
namespace Init
{
    int const minBoardSize = 24;
    int const maxBoardSize = 50;
    int const minMines = 3;
    int const maxMines = 8;

    bool rangeValidation(int const size) { return size > minBoardSize && size <= maxBoardSize; }

    std::vector<int> initializeAxis(int const size)
    {
        std::vector<int> axis;

        for (int i = 0; i < size; i++)
        {
            axis.push_back(i + 1);
        }
        return axis;
    }
    bool minesValidation(int const count) { return count >= minMines && count <= maxMines; }

    int getBoardDimension(std::string const &axisName)
    {
        int size = 0;
        std::cout << "Enter number of " << axisName << " (between 25 and 50): ";
        std::cin >> size;
        while (!rangeValidation(size))
        {
            std::cout << "Invalid value. Please try again: ";
            std::cin >> size;
        }
        return size;
    }

    int readMineCount()
    {
        int count = 0;
        std::cout << "Enter number of mines (between 3 and 8): ";
        std::cin >> count;
        while (!minesValidation(count))
        {
            std::cout << "Invalid value. Please try again: ";
            std::cin >> count;
        }
        return count;
    }

    /*void placeMinesForPlayer(Player &player, int count, int maxX, int maxY, Board &board)
    {
        player.mines.clear();

        std::cout << "\nRemaining mines: " << player.remainingMines << "\n";
        std::cout << "You may place your " << player.remainingMines << " mines now.\n";

        while (player.mines.size() < static_cast<size_t>(player.remainingMines))
        {
            int x, y;
            std::cout << "Place mine #" << (player.mines.size() + 1) << "\n";
            std::cout << "Enter X coordinate (1-" << maxX << "): ";
            std::cin >> x;
            std::cout << "Enter Y coordinate (1-" << maxY << "): ";
            std::cin >> y;

            if (x < 1 || x > maxX || y < 1 || y > maxY)
            {
                std::cout << "Invalid position. Try again.\n";
                continue;
            }

            bool validPlacement = true;

            int indexX = x - 1;
            int indexY = y - 1;
            if (board.grid[indexY][indexX].isTaken())
            {
                std::cout << "That cell is taken from a previous guess. Try again.\n";
                validPlacement = false;
            }

            for (const auto &disabled : player.disabledMineSpots)
            {
                if (disabled.getX() == x && disabled.getY() == y)
                {
                    std::cout << "You lost a mine there before. You can't reuse that cell.\n";
                    validPlacement = false;
                    break;
                }
            }

            for (const auto &mine : player.mines)
            {
                if (mine.cell.getX() == x && mine.cell.getY() == y)
                {
                    std::cout << "Already placed a mine there this turn. Try again.\n";
                    validPlacement = false;
                    break;
                }
            }

            if (!validPlacement)
                continue;

            player.mines.push_back(Mine(x, y));
        }
    }*/

    void printRemainingMines(const Player &player)
    {
        std::cout << "\nRemaining mines: " << player.remainingMines << "\n";
        std::cout << "You may place your " << player.remainingMines << " mines now.\n";
    }

    bool getMineCoordinates(int &x, int &y, int maxX, int maxY)
    {
        std::cout << "Enter X coordinate (1-" << maxX << "): ";
        std::cin >> x;
        std::cout << "Enter Y coordinate (1-" << maxY << "): ";
        std::cin >> y;

        return (x >= 1 && x <= maxX && y >= 1 && y <= maxY);
    }

    bool isValidPlacement(const Board &board, const Player &player, int x, int y)
    {
        int indexX = x - 1;
        int indexY = y - 1;

        if (board.grid[indexY][indexX].isTaken())
        {
            std::cout << "That cell is taken from a previous guess. Try again.\n";
            return false;
        }

        for (const auto &disabled : player.disabledMineSpots)
        {
            if (disabled.getX() == x && disabled.getY() == y)
            {
                std::cout << "You lost a mine there before. You can't reuse that cell.\n";
                return false;
            }
        }

        for (const auto &mine : player.mines)
        {
            if (mine.location.getX() == x && mine.location.getY() == y)
            {
                std::cout << "Already placed a mine there this turn. Try again.\n";
                return false;
            }
        }

        return true; // Valid placement
    }

    void placeMinesForPlayer(Player &player, int count, int maxX, int maxY, Board &board)
    {
        player.mines.clear();
        printRemainingMines(player); // Print remaining mines

        while (player.mines.size() < static_cast<size_t>(player.remainingMines))
        {
            int x = 0;
            int y = 0;

            if (!getMineCoordinates(x, y, maxX, maxY))
            {
                std::cout << "Invalid position. Try again.\n";
                continue;
            }

            if (!isValidPlacement(board, player, x, y))
            {
                continue; // Invalid placement, retry
            }

            player.mines.push_back(Mine(x, y)); // Place the mine
        }
    }

    // prints a player's mines
    void printPlayerMines(Player const &player, int playerNumber)
    {
        std::cout << "\nMines of the player " << playerNumber << ":\n";
        for (size_t i = 0; i < player.mines.size(); ++i)
        {
            std::cout << "Mine #" << (i + 1) << ": (" << player.mines[i].location.getX() << "," << player.mines[i].location.getY() << ")\n";
        }
    }
    void printGameSetup(int rows, int columns, int mines)
    {
        std::cout << "Setup completed:\n";
        std::cout << "Board of " << rows << " rows x " << columns << " columns\n";
        std::cout << "Each player has " << mines << " mines per turn\n";
    }

    void initializeGrid(Board &board)
    {
        board.grid.resize(board.axisY.size());

        for (size_t y = 0; y < board.axisY.size(); ++y)
        {
            board.grid[y].resize(board.axisX.size());
            for (size_t x = 0; x < board.axisX.size(); ++x)
            {
                board.grid[y][x] = Cell(board.axisX[x], board.axisY[y], CellStatus::Empty);
            }
        }
    }

}