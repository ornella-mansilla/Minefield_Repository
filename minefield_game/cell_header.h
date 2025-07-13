#pragma once

enum class CellStatus : char
{
    Empty = 'o',   // Empty cell
    Guess = '?',   // A guess has been made
    Bomb  = '*',   // Contains a mine
    Taken = 'x'    // Disabled cell (can no longer be used)
};


class Cell
{
private:
    int x;
    int y;
    CellStatus state;
public:
    Cell(int x, int y);
    Cell(int x, int y, CellStatus state);
    Cell();
    int getX() const;
    int getY() const;
    void setState(CellStatus newState);
    CellStatus getState() const;
    bool isTaken() const;
    char getSymbol() const;
};



