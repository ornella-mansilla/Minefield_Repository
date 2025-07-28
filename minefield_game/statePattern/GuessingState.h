#pragma once
#include "GameState.h"

class GuessingState : public game::State
{
public:
    void handle(Game& game) override;
};
