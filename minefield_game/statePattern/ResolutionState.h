#pragma once
#include "GameState.h"

bool cellMatches(const Cell& a, const Cell& b);
class ResolutionState : public GameState
{
public:
    void handle(GameContext& context) override;

};

