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
    CellStatus status;
public:
    Cell(int x, int y);
    Cell(int x, int y, CellStatus status);
    Cell();
    int getX() const;
    int getY() const;
    void setState(CellStatus newStatus);
    CellStatus getState() const;
    bool isTaken() const;
    char getSymbol() const;
};



