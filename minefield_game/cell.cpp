
#include "cell_header.h"

/*class Cell
{
    public:
        Cell::Cell(int x, int y)
        : x(x)
        , y(y)
        , state(CellState::Empty)
        {

        }

        void Cell::setState(CellState newState) {state = newState;}

        CellState Cell::getState() const {return state;}

        bool Cell::isTaken() const {return state == CellState::Taken;}

        char Cell::getSymbol() const {return static_cast<char>(state);}

        int getX() {return x;}

    private:
        int x;
        int y;
        CellState state;

};*/
Cell::Cell(int x, int y)
    : x(x), y(y), state(CellState::Empty){}
Cell::Cell(int x, int y, CellState state)
    : x(x), y(y), state(state) {}

Cell::Cell() = default;
void Cell::setState(CellState newState) { state = newState; }

CellState Cell::getState() const { return state; }

bool Cell::isTaken() const { return state == CellState::Taken; }

char Cell::getSymbol() const { return static_cast<char>(state); }

int Cell::getX() const { return x; }
int Cell::getY() const { return y; }
