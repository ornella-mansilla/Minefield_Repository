#include "cell_header.h"

Cell::Cell(int x, int y)
    : x(x), y(y), status(CellStatus::Empty){}
Cell::Cell(int x, int y, CellStatus status)
    : x(x), y(y), status(status) {}

Cell::Cell() = default;
void Cell::setState(CellStatus newStatus) { status = newStatus; }
CellStatus Cell::getState() const { return status; }
bool Cell::isTaken() const { return status == CellStatus::Taken; }
char Cell::getSymbol() const { return static_cast<char>(status); }
int Cell::getX() const { return x; }
int Cell::getY() const { return y; }
