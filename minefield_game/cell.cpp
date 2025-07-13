#include "cell_header.h"

Cell::Cell(int x, int y)
    : x(x), y(y), state(CellStatus::Empty){}
Cell::Cell(int x, int y, CellStatus state)
    : x(x), y(y), state(state) {}

Cell::Cell() = default;
void Cell::setState(CellStatus newState) { state = newState; }
CellStatus Cell::getState() const { return state; }
bool Cell::isTaken() const { return state == CellStatus::Taken; }
char Cell::getSymbol() const { return static_cast<char>(state); }
int Cell::getX() const { return x; }
int Cell::getY() const { return y; }
