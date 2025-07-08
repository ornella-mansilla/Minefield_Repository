#pragma once
#include <vector>
#include "cell_header.h"
struct Mine;
struct Player
{
    std::vector<Mine> mines;
    std::vector<Cell> guesses; //recordar que la cantidad de adivinanzas que tenga depende la cantidad de minas no descubiertas del contrincante
    int remainingMines; //la cantidad de minas que puedo usar o colocar aún
};
struct Mine
{
    Cell cell;
    Mine(int x, int y) : cell(x, y) {}
};