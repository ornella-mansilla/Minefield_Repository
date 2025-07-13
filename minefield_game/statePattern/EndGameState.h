#pragma once
#include "GameState.h"

class EndGameState : public GameState
{
public:
    void handle(GameContext& context) override;
};
