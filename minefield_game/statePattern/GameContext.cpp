#include "GameContext.h"
#include "GameState.h"

void GameContext::setState(std::unique_ptr<GameState> state)
{
    currentState = std::move(state);
}

void GameContext::run()
{
    while (currentState)
    {
        currentState->handle(*this);
    }
}
