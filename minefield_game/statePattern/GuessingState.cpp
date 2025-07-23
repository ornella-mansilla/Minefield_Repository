#include "GameContext.h"
#include "GuessingState.h"
#include "ResolutionState.h"
#include <init_header.h>
#include <iostream>

bool getGuessCoordinates(int &x, int &y, const Board &board)
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
void guess(Player &player, int &guesses, GameContext &context)
{
    std::cout << "Player " << player.id << ": You have " << guesses << " guesses. \n";

        while (player.guesses.size() < static_cast<size_t>(guesses))
    {
        int x = 0;
        int y = 0;

        if (!getGuessCoordinates(x, y, context.board))
        {
            std::cout << "Invalid guess location. Try again.\n";
                continue;
        }

        Cell guess(x, y, CellStatus::Guess);

        if (!isDuplicateGuess(player, guess))
        {
            player.guesses.push_back(guess); // add the guess if it's valid and not a duplicate
        }
    }
}
void GuessingState::handle(GameContext &context)
{
    std::cout << "\n--- Guessing Phase ---\n";

    context.player1.guesses.clear();
    context.player2.guesses.clear();

    int guesses1 = context.player2.mines.size();
    int guesses2 = context.player1.mines.size();

    guess(context.player1, guesses1, context);
    guess(context.player2, guesses2, context);

    /*std::cout << "Player 1: You have " << guesses1 << " guesses.\n";
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
    }*/

    context.setState(std::make_unique<ResolutionState>());
}

// funcion abstracta para lo de arriba:

/*void guess(Player &player, int &guesses, GameContext &context)
{
    std::cout << "Player " << player.id << ": You have " << guesses << " guesses.\n";
    while (player.guesses.size() < static_cast<size_t>(guesses))
    {
        int x = 0;
        int y = 0;
        std::cout << "Guess #" << (player.guesses.size() + 1) << " - Enter X: ";
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
        for (const auto &g : context.player1.guesses)
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
            player.guesses.push_back(guess);
        }
    }
}*/



