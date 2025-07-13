#include "GameContext.h"
#include "GuessingState.h"
#include "ResolutionState.h"
#include "../init_header.h"
#include <iostream>

void GuessingState::handle(GameContext& context)
{
    std::cout << "\n--- Guessing Phase ---\n";

    context.player1.guesses.clear();
    context.player2.guesses.clear();

    int guesses1 = context.player2.mines.size();
    int guesses2 = context.player1.mines.size();

    std::cout << "Player 1: You have " << guesses1 << " guesses.\n";
    while (context.player1.guesses.size() < static_cast<size_t>(guesses1))
    {
        int x;
        int y;
        std::cout << "Guess #" << context.player1.guesses.size() + 1 << " - Enter X: ";
        std::cin >> x;
        std::cout << "Enter Y: ";
        std::cin >> y;

        if (x < 1 || x > static_cast<int>(context.board.axisX.size()) || y < 1 || y > static_cast<int>(context.board.axisY.size()))
        {
            std::cout << "Invalid guess location. Try again.\n";
            continue;
        }

        Cell guess(x, y, CellStatus::Guess);

        bool duplicate = false;
        for (const auto& g : context.player1.guesses)
        {
            if (cellMatches(g, guess))
            {
                std::cout << "You already guessed that. Try again.\n";
                duplicate = true;
                break;
            }
        }
        if (!duplicate)
        {
            context.player1.guesses.push_back(guess);
        }
    }

    std::cout << "\nPlayer 2: You have " << guesses2 << " guesses.\n";
    while (context.player2.guesses.size() < static_cast<size_t>(guesses2))
    {
        int x, y;
        std::cout << "Guess #" << context.player2.guesses.size() + 1 << " - Enter X: ";
        std::cin >> x;
        std::cout << "Enter Y: ";
        std::cin >> y;

        if (x < 1 || x > static_cast<int>(context.board.axisX.size()) || y < 1 || y > static_cast<int>(context.board.axisY.size()))
        {
            std::cout << "Invalid guess location. Try again.\n";
            continue;
        }

        Cell guess(x, y, CellStatus::Guess);

        bool duplicate = false;
        for (const auto& g : context.player2.guesses)
        {
            if (cellMatches(g, guess))
            {
                std::cout << "You already guessed that. Try again.\n";
                duplicate = true;
                break;
            }
        }
        if (!duplicate)
        {
            context.player2.guesses.push_back(guess);
        }
    }

    context.setState(std::make_unique<ResolutionState>());
}