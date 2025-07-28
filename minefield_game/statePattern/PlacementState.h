#pragma once
#include "GameState.h"

class PlacementState : public game::State
{
public:
    void handle(Game& game) override;
};
