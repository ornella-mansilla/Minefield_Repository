#pragma once
#include "player_header.h"
#include "board_header.h"
namespace Init
{
    bool rangeValidation(int const size);
    std::vector<int> initializeAxis(int const size);
    bool minesValidation(int const count);
    int getBoardDimension(const std::string& axisName) ;
    int getMineCount() ;   
    void placeMines(Player &player, int count, int maxX, int maxY);
    void printPlayerMines(const Player& player, int playerNumber) ;
    void printGameSetup(int rows, int columns, int mines) ;
    void initializeGrid(Board &board);
}