#include "GameContext.h"
#include "GuessingState.h"
#include "ResolutionState.h"
#include <init.h>
#include <iostream>

bool getGuessCoordinates(int& x, int& y, const Board& board)
{
    std::cout << "Enter X: ";
    std::cin >> x;
    std::cout << "Enter Y: ";
    std::cin >> y;

    return (x >= 1 && x <= static_cast<int>(board.axisX.size()) &&
            y >= 1 && y <= static_cast<int>(board.axisY.size()));
}

bool isDuplicateGuess(Player const& player, Cell const& guess)
{
    for (Cell const &g : player.guesses)
    {
        if (cellMatches(g, guess))
        {
            std::cout << "You already guessed that. Try again.\n";
                return true; // Found a duplicate guess
        }
    }
    return false; // No duplicate found
}
void guess(Player& player, int& guesses, Game& game)
{
    std::cout << "Player " << player.id << ": You have " << guesses << " guesses. \n";

        while (player.guesses.size() < static_cast<size_t>(guesses))
    {
        int x = 0;
        int y = 0;

        if (!getGuessCoordinates(x, y, game.context.board))
        {
            std::cout << "Invalid guess location. Try again.\n";
            continue;
        }
        {
            std::cout << "Invalid guess location. Try again.\n";
                continue;
        }

        Cell guess{x, y, CellStatus::Guess};

        if (!isDuplicateGuess(player, guess))
        {
            player.guesses.push_back(guess); // add the guess if it's valid and not a duplicate
        }
    }
}
void GuessingState::handle(Game& game)
{
    std::cout << "\n--- Guessing Phase ---\n";

    game.context.player1.guesses.clear();
    game.context.player2.guesses.clear();

    int guesses1 = game.context.player1.mines.size();
    int guesses2 = game.context.player2.mines.size();

    guess(game.context.player1, guesses1, game);
    guess(game.context.player2, guesses2, game);

    game.logic.setState(std::make_unique<ResolutionState>());
}



