#pragma once
#include "GameState.h"

class GameSetUpState : public GameState
{
public:
    void handle(GameContext& context) override;
};
