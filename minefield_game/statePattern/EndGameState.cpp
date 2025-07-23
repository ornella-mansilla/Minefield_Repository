#include "GameContext.h"
#include "EndGameState.h"
#include "PlacementState.h"
#include <board_header.h>
#include <iostream>

void EndGameState::handle(GameContext& context)
{
    std::cout << "\n--- Game Over ---\n";

    int p1 = context.player1.remainingMines;
    int p2 = context.player2.remainingMines;

    if (p1 > p2)
    {
        std::cout << "Player 1 wins!\n";
        context.setState(nullptr);
    } else if (p2 > p1){
        std::cout << "Player 2 wins!\n";
        context.setState(nullptr);
    } else{
        std::cout << "It's a draw!\n";
        context.setState(nullptr);
    }
}
