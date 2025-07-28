#pragma once
#include <vector>
#include "cell.h"
struct Mine;
struct Player
{
    //deberia tener un id
    int id; // Player ID
    std::vector<Mine> mines;
    std::vector<Cell> guesses;
    std::vector<Cell> disabledMineSpots; // locations where own mines were destroyed
    int remainingMines; // the number of mines the player can still place or use
};

struct Mine
{
    Cell location;
    Mine(int x, int y) : location{x, y} {}
};