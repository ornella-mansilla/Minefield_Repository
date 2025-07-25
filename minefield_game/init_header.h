#pragma once
#include <iostream>
#include "player_header.h"
#include "board_header.h"
namespace Init
{
    bool rangeValidation(int size);
    std::vector<int> initializeAxis(int size);
    bool minesValidation(int count);
    int getBoardDimension(std::string const& axisName);
    int readMineCount();
    void placeMinesForPlayer(Player& player, int count, int maxX, int maxY, Board& board);
    void printPlayerMines(Player const& player, int playerNumber);
    void printGameSetup(int rows, int columns, int mines);
    void initializeGrid(Board& board);
}