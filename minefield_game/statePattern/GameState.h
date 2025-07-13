#pragma once

class GameContext; // forward declaration

class GameState
{
public:
    virtual ~GameState() = default;
    virtual void handle(GameContext& context) = 0;
};
