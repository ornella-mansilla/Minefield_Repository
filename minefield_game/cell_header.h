#pragma once
#include <vector>

enum class CellState : char
{
    Empty = 'o',   // Celda vacía
    Guess = '?',   // Adivinanza realizada
    Bomb  = '*',   // Contiene una mina
    Taken = 'x'    // Celda deshabilitada (no se puede usar más)
};

class Cell {
private:
    int x;
    int y;
    CellState state;
public:
    Cell(int x, int y);
    Cell(int x, int y, CellState state);
    Cell();
    int getX() const;
    int getY() const;
    void setState(CellState newState);
    CellState getState() const;
    bool isTaken() const;
    char getSymbol() const;
};



