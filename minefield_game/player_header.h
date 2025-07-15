#pragma once
#include <vector>
#include "cell_header.h"
struct Mine;
struct Player
{
    std::vector<Mine> mines;
    std::vector<Cell> guesses;
    std::vector<Cell> disabledMineSpots; // locations where own mines were destroyed
    int remainingMines; // the number of mines the player can still place or use
};

struct Mine
{
    Cell cell;
    Mine(int x, int y) : cell(x, y) {}
};