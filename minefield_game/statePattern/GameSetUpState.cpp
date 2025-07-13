#include "GameContext.h"
#include "GameSetUpState.h"
#include "PlacementState.h"
#include "../init_header.h"
#include <iostream>

void GameSetUpState::handle(GameContext& context)
{
    std::cout << "=== Game Setup ===\n";

    context.columns = Init::getBoardDimension("columns");
    context.rows = Init::getBoardDimension("rows");
    context.mines = Init::getMineCount();
    context.board.axisX = Init::initializeAxis(context.columns);
    context.board.axisY = Init::initializeAxis(context.rows);
    context.player1.remainingMines = context.mines;
    context.player2.remainingMines = context.mines;

    Init::printGameSetup(context.rows, context.columns, context.mines);
    Init::initializeGrid(context.board);

    context.setState(std::make_unique<PlacementState>());
}
