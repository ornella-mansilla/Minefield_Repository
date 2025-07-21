#include "GameContext.h"
#include "ResolutionState.h"
#include "EndGameState.h"
#include "PlacementState.h"
#include "../cell_header.h"
#include <iostream>
#include <algorithm>
// ya hice la separacion en distintas funciones del process guesses y el ovelapping mines
bool cellMatches(Cell const &a, Cell const &b)
{
    return a.getX() == b.getX() && a.getY() == b.getY();
}

void checkHits(std::string const &attackerName, Player &attacker, Player &defender)
{
    std::vector<Mine> updatedMines;
    for (const auto &mine : defender.mines)
    {
        bool hit = false;
        for (const auto &guess : attacker.guesses)
        {
            if (cellMatches(mine.cell, guess))
            {
                std::cout << attackerName << " hit a mine at (" << mine.cell.getX() << ", " << mine.cell.getY() << ")!\n";
                hit = true;
                break;
            }
        }
        if (!hit)
        {
            updatedMines.push_back(mine);
        }
    }

    // save destroyed mines
    for (const auto &oldMine : defender.mines)
    {
        bool wasDestroyed = std::none_of(updatedMines.begin(), updatedMines.end(), [&oldMine](const Mine &m)
                                         { return cellMatches(m.cell, oldMine.cell); });

        if (wasDestroyed)
        {
            defender.disabledMineSpots.push_back(oldMine.cell);
        }
    }

    defender.mines = updatedMines;
}

void processGuesses(std::string const &attackerName, Player &attacker, Player &defender, Board &board)
{
    // check if the attacker hit any mines of the defender
    checkHits(attackerName, attacker, defender);
    // check if the attacker guessed where he had a mine
    checkSelfDamage(attacker);


    /*std::vector<Mine> updatedMines;
    for (const auto &mine : defender.mines)
    {
        bool hit = false;
        for (const auto &guess : attacker.guesses)
        {
            if (cellMatches(mine.cell, guess))
            {
                std::cout << attackerName << " hit a mine at (" << mine.cell.getX() << ", " << mine.cell.getY() << ")!\n";
                hit = true;
                break;
            }
        }
        if (!hit)
        {
            updatedMines.push_back(mine);
        }
    }

    // save destroyed mines
    for (const auto &oldMine : defender.mines)
    {
        bool wasDestroyed = std::none_of(updatedMines.begin(), updatedMines.end(), [&oldMine](const Mine &m)
                                         { return cellMatches(m.cell, oldMine.cell); });

        if (wasDestroyed)
        {
            defender.disabledMineSpots.push_back(oldMine.cell);
        }
    }

    defender.mines = updatedMines;

    // self-damage: check if the player guessed where he had a mine
    std::vector<Mine> updatedOwnMines;
    for (const auto &mine : attacker.mines)
    {
        bool selfHit = false;
        for (const auto &guess : attacker.guesses)
        {
            if (cellMatches(mine.cell, guess))
            {
                std::cout << "Oops! You guessed your own mine at (" << mine.cell.getX() << ", " << mine.cell.getY() << ")\n";
                attacker.disabledMineSpots.push_back(mine.cell);
                selfHit = true;
                break;
            }
        }
        if (!selfHit)
        {
            updatedOwnMines.push_back(mine);
        }
    }

    attacker.mines = updatedOwnMines;*/

    // mark guessed cells as "Taken"
    for (const auto &guess : attacker.guesses)
    {
        int gx = guess.getX() - 1;
        int gy = guess.getY() - 1;
        board.grid[gy][gx].setState(CellStatus::Taken);
    }
}
void checkSelfDamage(Player &attacker)
{
    std::vector<Mine> updatedOwnMines;
    for (const auto &mine : attacker.mines)
    {
        bool selfHit = false;
        for (const auto &guess : attacker.guesses)
        {
            if (cellMatches(mine.cell, guess))
            {
                std::cout << "Oops! You guessed your own mine at (" << mine.cell.getX() << ", " << mine.cell.getY() << ")\n";
                attacker.disabledMineSpots.push_back(mine.cell);
                selfHit = true;
                break;
            }
        }
        if (!selfHit)
        {
            updatedOwnMines.push_back(mine);
        }
    }

    attacker.mines = updatedOwnMines;
}

std::vector<Mine> removeOverlaps(const std::vector<Mine>& mines, const std::vector<Mine>& otherMines)
{
    std::vector<Mine> cleaned;
    for (Mine const& m : mines)
    {
        bool overlap = std::any_of(otherMines.begin(), otherMines.end(), 
                                   [&m](Mine const& other) { return cellMatches(m.cell, other.cell); });
        if (!overlap)
        {
            cleaned.push_back(m);
        }
    }
    return cleaned;
}

void removeOverlappingMines(Player &p1, Player &p2)
{
    auto p1Cleaned = removeOverlaps(p1.mines, p2.mines);
    auto p2Cleaned = removeOverlaps(p2.mines, p1.mines);

    if (p1.mines.size() != p1Cleaned.size() || p2.mines.size() != p2Cleaned.size())
    {
        std::cout << "Some overlapping mines were neutralized!\n";
    }

    p1.mines = std::move(p1Cleaned);
    p2.mines = std::move(p2Cleaned);

    //metodo viejo:
    /*std::vector<Mine> p1Cleaned, p2Cleaned;

    for (const auto &m1 : p1.mines)
    {
        bool overlap = false;
        for (const auto &m2 : p2.mines)
        {
            if (cellMatches(m1.cell, m2.cell))
            {
                overlap = true;
                break;
            }
        }
        if (!overlap)
        {
            p1Cleaned.push_back(m1);
        }
    }

    for (const auto &m2 : p2.mines)
    {
        bool overlap = false;
        for (const auto &m1 : p1.mines)
        {
            if (cellMatches(m2.cell, m1.cell))
            {
                overlap = true;
                break;
            }
        }
        if (!overlap)
        {
            p2Cleaned.push_back(m2);
        }
    }

    if (p1.mines.size() != p1Cleaned.size() || p2.mines.size() != p2Cleaned.size())
    {
        std::cout << "Some overlapping mines were neutralized!\n";
    }

    p1.mines = p1Cleaned;
    p2.mines = p2Cleaned;*/
}

void ResolutionState::handle(GameContext &context)
{

    std::cout << "\n--- Resolution Phase ---\n";

    removeOverlappingMines(context.player1, context.player2);

    processGuesses("Player 1",context.player1, context.player2, context.board);
    processGuesses("Player 2",context.player2, context.player1, context.board);

    // update remaining mines
    context.player1.remainingMines = context.player1.mines.size();
    context.player2.remainingMines = context.player2.mines.size();

    std::cout << "\nCurrent board state:\n";
    std::cout << "\nPlayer 1 remaining mines: " << std::endl;
    BoardUtils::printBoardPerPlayer(context.board, context.player1);
    std::cout << "\nPlayer 2 remaining mines: " << std::endl;
    BoardUtils::printBoardPerPlayer(context.board, context.player2);

    if (context.player1.remainingMines == 0 && context.player2.remainingMines == 0)
    {
        std::cout << "\nBoth players lost all mines at the same time!\n";
        context.setState(std::make_unique<EndGameState>());
        return;
    }
    if (context.player1.remainingMines == 0 || context.player2.remainingMines == 0)
    {
        context.setState(std::make_unique<EndGameState>());
        return;
    }
    context.setState(std::make_unique<PlacementState>());
}
