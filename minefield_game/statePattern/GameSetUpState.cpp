#include "GameContext.h"
#include "GameSetUpState.h"
#include "PlacementState.h"
#include <init_header.h>
#include <iostream>

//se ve super mal el table y la parte de placement no me dice que mina esto poniendo en ese momento.
void GameSetUpState::handle(GameContext& context)
{
    std::cout << "=== Game Setup ===\n";

    context.columns = Init::getBoardDimension("columns");
    context.rows = Init::getBoardDimension("rows");
    context.mines = Init::readMineCount();
    context.board.axisX = Init::initializeAxis(context.columns);
    context.board.axisY = Init::initializeAxis(context.rows);
    context.player1.remainingMines = context.mines;
    context.player1.id = 1;
    context.player2.remainingMines = context.mines;
    context.player2.id = 2;

    Init::printGameSetup(context.rows, context.columns, context.mines);
    Init::initializeGrid(context.board);

    context.setState(std::make_unique<PlacementState>());
}
