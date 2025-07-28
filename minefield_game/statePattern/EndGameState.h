#pragma once
#include "GameState.h"

class EndGameState : public game::State
{
public:
    void handle(Game& game) override;
};
