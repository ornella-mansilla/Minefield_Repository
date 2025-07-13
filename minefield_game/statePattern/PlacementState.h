#pragma once
#include "GameState.h"

class PlacementState : public GameState {
public:
    void handle(GameContext& context) override;
};
