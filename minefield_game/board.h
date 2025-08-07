#pragma once
#include <vector>
#include "player.h"

struct Board
{
    std::vector<std::vector<Cell>> grid;
};
namespace BoardUtils
{
    void printBoardPerPlayer(Board const& board, Player const& player);
}