#include "GameContext.h"
#include "PlacementState.h"
#include "GuessingState.h"
#include <init.h>
#include <board.h>
#include <iostream>

void PlacementState::handle(Game& game)
{
    std::cout << "\n--- Placement Phase ---\n";

    std::cout << "Player 1, place your mines:\n";
    Init::placeMinesForPlayer(game.context.player1, game.context.player1.remainingMines, game.context.board.axisX.size(), game.context.board.axisY.size(), game.context.board);
    BoardUtils::printBoardPerPlayer(game.context.board, game.context.player1);

    std::cout << "\nPlayer 2, place your mines:\n";
    Init::placeMinesForPlayer(game.context.player2, game.context.player2.remainingMines, game.context.board.axisX.size(), game.context.board.axisY.size(), game.context.board);
    BoardUtils::printBoardPerPlayer(game.context.board, game.context.player2);
    game.logic.setState(std::make_unique<GuessingState>());
}
