/*

Minefield
=========

- Tablero tipo buscaminas (es un solo tablero)
- Tamaño del mismo determinado por el usuario
    - Ningún eje puede ser menor a 24 ni mayor que 50
    - Cada eje puede tener su propio tamaño
- La cantidad de minas en juego también es definida por el usuario
    - No puede ser menor que 3 ni mayor que 8
- Se juega de a dos, donde el segundo jugador es controlado por la computadora
    - Bonus: hotseat para pvp (misma PC, que no pantalleen)
- Cada turno, los jugadores re-colocan las minas y hacen sus adivinanzas
    - En caso de colocar una mina en el mismo casillero, ambas quedan eliminadas
    - El procesamiento del resultado de estas acciones se realiza una vez que todos los
      jugadores las completaron
- Una mina no puede ser colocada en un lugar donde ya se hizo un intento de adivinanza
  ni donde ya hubiera sido detectada una mina
- Cada mina detectada se resta de las que cada jugador coloca al principio de cada turno
- Los jugadores introducen todas sus adivinanzas en el mismo momento (tantas adivinanzas
  como minas tenga el rival) y una vez que todas fueron introducidas, se procede a
  verificar el impacto de las mismas.
  - Cada casillero donde se hizo una adivinanza pasa a quedar permanentemente deshabilitado
    a partir de la siguiente ronda.
  - Cuidado! Recordá dónde pusiste tus minas porque adivinar un casillero donde había una
    mina propia te la resta!
- Gana el primer jugador en detectar todas las minas del rival.
    - En caso de que las últimas minas estuvieran en el mismo lugar o se adivinen sus
      posiciones en simultáneo, se declara empate.

*/

#include <iostream>
#include <stdlib.h>
#include <vector>

void clearConsoleBuffer();

void clearConsoleBuffer()
{
    char const* const kClearConsoleBufferCommand = "cls";
    system(kClearConsoleBufferCommand);
}

struct State;
struct GameContext;
typedef State NextState;

typedef NextState(*StateUpdateFn)(GameContext&);

struct State
{
    StateUpdateFn updateFunction;
};

struct Board {};

struct GameContext
{
    State currentState;
};

NextState stateQuitUpdate(GameContext& context)
{
    return { nullptr };
}

NextState stateOptionsUpdate(GameContext& context)
{
    std::cout << "Inside options\n";

    return context.currentState;
}

NextState stateMainMenuUpdate(GameContext& context)
{
    std::cout << "Inside main menu\n";

    int userSelection = 0;
    std::cout << "Welcome to Game! Select an option to continue:\n1. Options\n2. Quit\n> ";
    std::cin >> userSelection;
    if (userSelection == 1)
    {
        std::cout << "MainMenu: User selected options\n";
        return { &stateOptionsUpdate };
    }
    else if (userSelection == 2)
    {
        std::cout << "MainMenu: User selected quit\n";
        return { &stateQuitUpdate };
    }

    std::cout << "MainMenu: User did not select anything\n";
    return context.currentState;
}

void runMainLoop()
{
    bool quit = false;
    GameContext context;
    context.currentState = { &stateMainMenuUpdate };
    while (!quit)
    {
        if (context.currentState.updateFunction != nullptr)
        {
            context.currentState = (*context.currentState.updateFunction)(context);
        }
        quit = context.currentState.updateFunction == nullptr;
    }
}

int main(int argc, char const* argv[])
{
    runMainLoop();

    return 0;
}