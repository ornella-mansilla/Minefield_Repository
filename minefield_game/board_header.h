#pragma once
#include <vector>
#include "player_header.h"

struct Board
{
    std::vector<int> axisX;  //columns      
    std::vector<int> axisY;  //rows
    std::vector<std::vector<Cell>> grid;

};
namespace BoardUtils
{
    void printBoardPerPlayer(const Board& board, const Player& player);
}