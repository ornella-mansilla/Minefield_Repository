#pragma once
#include "GameState.h"

class GameSetUpState : public game::State
{
public:
    void handle(Game& game) override;
};
