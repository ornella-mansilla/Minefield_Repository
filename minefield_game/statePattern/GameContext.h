#pragma once
#include <memory>
#include "../board_header.h"
#include "../player_header.h"

class GameState;

class GameContext
{
private:
    std::unique_ptr<GameState> currentState;

public:
    Board board;
    Player player1;
    Player player2;
    int columns;
    int rows;
    int mines;

    void setState(std::unique_ptr<GameState> state);
    void run();
};
