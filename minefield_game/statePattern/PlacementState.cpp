#include "GameContext.h"
#include "PlacementState.h"
#include "GuessingState.h"
#include <init_header.h>
#include <board_header.h>
#include <iostream>

void PlacementState::handle(GameContext& context)
{
    std::cout << "\n--- Placement Phase ---\n";

    std::cout << "Player 1, place your mines:\n";
    Init::placeMinesForPlayer(context.player1, context.player1.remainingMines, context.board.axisX.size(), context.board.axisY.size(), context.board);
    BoardUtils::printBoardPerPlayer(context.board, context.player1);

    std::cout << "\nPlayer 2, place your mines:\n";
    Init::placeMinesForPlayer(context.player2, context.player2.remainingMines, context.board.axisX.size(), context.board.axisY.size(), context.board);
    BoardUtils::printBoardPerPlayer(context.board, context.player2);
    context.setState(std::make_unique<GuessingState>());
}
