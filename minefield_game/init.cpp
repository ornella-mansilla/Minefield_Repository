#include <iostream>
#include <vector>
#include "init_header.h"
#include "cell_header.h"
#include "player_header.h"
namespace Init
{
    bool rangeValidation(int const size) { return size > 24 && size <= 50; }

    std::vector<int> initializeAxis(int const size)
    {
        std::vector<int> axis;

        for (int i = 0; i < size; i++)
        {
            axis.push_back(i + 1);
        }
        return axis;
    }
    bool minesValidation(int const count) { return count >= 3 && count <= 8; }

    int getBoardDimension(const std::string &axisName)
    {
        int size = 0;
        std::cout << "Ingrese cantidad de " << axisName << " (entre 25 y 50): ";
        std::cin >> size;
        while (!rangeValidation(size))
        {
            std::cout << "Valor invalido. Intente de nuevo: ";
            std::cin >> size;
        }
        return size;
    }

    int getMineCount()
    {
        int count = 0;
        std::cout << "Ingrese cantidad de minas (entre 3 y 8): ";
        std::cin >> count;
        while (!minesValidation(count))
        {
            std::cout << "Cantidad invalida. Intente de nuevo: ";
            std::cin >> count;
        }
        return count;
    }

    void placeMines(Player &player, int count, int maxX, int maxY)
    {
        while (player.mines.size() < count)
        {
            int x, y;
            std::cout << "Coloque mina #" << (player.mines.size() + 1) << "\n";
            std::cout << "Ingrese coordenada X (1-" << maxX << "): ";
            std::cin >> x;
            std::cout << "Ingrese coordenada Y (1-" << maxY << "): ";
            std::cin >> y;

            // valida que esté dentro del tablero
            if (x < 1 || x > maxX || y < 1 || y > maxY)
            {
                std::cout << "Coordenadas fuera del tablero. Intente de nuevo.\n";
                continue;
            }

            // valida que no haya ya una mina ahí
            bool exists = false;
            for (size_t i = 0; i < player.mines.size(); i++)
            {
                if (player.mines[i].cell.getX() == x && player.mines[i].cell.getY() == y)
                {
                    exists = true;
                    break;
                }
            }
            if (exists)
            {
                std::cout << "Ya hay una mina en esa celda. Intente otra.\n";
                continue;
            }

            Mine newMine(x, y);
            player.mines.push_back(newMine);
        }
    }

    // imprime minas de un jugador
    void printPlayerMines(const Player &player, int playerNumber)
    {
        std::cout << "\nMinas del Jugador " << playerNumber << ":\n";
        for (size_t i = 0; i < player.mines.size(); ++i)
        {
            std::cout << "Mina #" << i + 1 << ": (" << player.mines[i].cell.getX() << "," << player.mines[i].cell.getY() << ")\n";
        }
    }
    void printGameSetup(int rows, int columns, int mines)
    {
        std::cout << "Configuracion completada:\n";
        std::cout << "Tablero de " << rows << " filas x " << columns << " columnas\n";
        std::cout << "Cada jugador tiene " << mines << " minas por turno\n";
    }

    void initializeGrid(Board &board)
    {
        board.grid.resize(board.axisY.size());

        for (size_t y = 0; y < board.axisY.size(); ++y)
        {
            board.grid[y].resize(board.axisX.size());
            for (size_t x = 0; x < board.axisX.size(); ++x)
            {
                board.grid[y][x] = Cell(board.axisX[x], board.axisY[y], CellState::Empty);
            }
        }
    }

}