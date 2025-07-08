#include <iostream>
#include <iomanip>
#include "board_header.h"

/*void showBoard(std::vector<std::vector<int>>& board)
{
    std::cout << "  ";
    for (int j = 0; j < board[0].size(); ++j)
    {
        std::cout << std::setw(3) << j;
    }
    std::cout << std::endl;
    for (int i = 0; i < board.size(); ++i)
    {
        std::cout << std::setw(2) << i;
        for (int k = 0; k < board[i].size(); ++k)
        {
            std::cout << std::setw(3) << board[i][k];
        }
        std::cout << std::endl;
    }
}*/
/*void showBoard(const Board& board)
{
    // Imprimir encabezado columnas
    std::cout << "   ";
    for (size_t j = 0; j < board.axisX.size(); ++j)
    {
        std::cout << std::setw(3) << board.axisX[j];
    }
    std::cout << std::endl;

    // Imprimir filas
    for (size_t i = 0; i < board.grid.size(); ++i)
    {
        std::cout << std::setw(2) << board.axisY[i];  // Etiqueta fila
        for (size_t k = 0; k < board.grid[i].size(); ++k)
        {
            char symbol = static_cast<char>(board.grid[i][k].getState());
            std::cout << std::setw(3) << symbol;
        }
        std::cout << std::endl;
    }
}*/
namespace BoardUtils
{
    /*void printBoard(const Board& board)
    {
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
                char symbol = static_cast<char>(board.grid[y][x].getState());
                std::cout << symbol << "  ";
            }
            std::cout << "\n";
        }
    }*/
    
    /*void printBoardPerPlayer(Board& board, const Player& player)
    {
        for (size_t i = 0; i < player.mines.size(); ++i) 
        {
            int x = player.mines[i].cell.getX();
            int y = player.mines[i].cell.getY();
            int indexX = x - 1;
            int indexY = y - 1;
            board.grid[indexY][indexX].setState(CellState::Bomb);
        }
    }*/

    void printBoardPerPlayer(const Board& board, const Player& player)
    {
        // Imprimir encabezado columnas
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
                // Chequeo si esta celda es mina del jugador
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

                if (isMineForPlayer)
                    std::cout << "*  "; // Mina visible para este jugador
                else
                    std::cout << board.grid[y][x].getSymbol() << "  "; // Estado real de la celda
            }
            std::cout << "\n";
        }
    }
    
}