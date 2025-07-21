#pragma once
#include "GameState.h"

bool cellMatches(Cell const& a, Cell const& b);
class ResolutionState : public GameState
{
public:
    void handle(GameContext& context) override;

};

