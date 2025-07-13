#pragma once
#include "GameState.h"

class GuessingState : public GameState
{
public:
    void handle(GameContext& context) override;
};
