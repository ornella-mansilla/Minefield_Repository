#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "cell_header.h"
#include "init_header.h"
#include "player_header.h"
#include "board_header.h"

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
// tengo el estado de juego no iniciado
// tengo el estado inicial en el que pido los valores de los ejes
// tengo el estado de turnos (turno del jugador 1 y turno del jugador 2)
// tengo el estado de procesamiento de resultados
// tengo el estado final de finalizacion del juego con el ganador o el empate
namespace game
{
    // de esta manera puedo devolver solo true o false para el valor de los ejes de la grilla
    /*bool rangeValidation(int const size)
    {
        return size > 24 && size <= 50;
    }//del inicio

    // lo que hace es devolver el vector del eje x o y con su respectivo tamaño
    // ej: si quiero 25 columnas, deberia poner 25, que pase la validación y luego le asigne un vector de 25 posiciones al eje x
    std::vector<int> initializeAxis(int const size)
    {
        std::vector<int> axis;

        for(int i = 0; i < size; i++)
        {
            axis.push_back(i+1);
        }
        return axis;
    }//del inicio


    bool minesValidation(int const count)
    {
        return count >= 3 && count <= 8;
    }//del inicio*/

    /*struct Board
    {
        std::vector<int> axisX;  //columns
        std::vector<int> axisY;  //rows
    };*/
    /*struct Cell
    {
        int x;
        int y;
    };*/
    /*struct Mine
    {
        Cell cell;
    };*/

}
/*struct Player
{
    std::vector<game::Mine> mines;
    std::vector<game::Cell> guesses; //recordar que la cantidad de adivinanzas que tenga depende la cantidad de minas no descubiertas del contrincante
    int remainingMines; //la cantidad de minas que puedo usar o colocar aún
};*/

// lo que busco es asignar las minas a una determinada celda por jugador
// para ello, le paso ref del jugador, la cantidad de minas que pueden usarse y la cantidad de filas y columnas
/*void placeMines(Player& player, int count, int maxX, int maxY)
{
    while (player.mines.size() < count)
    {
        int x, y;
        std::cout << "Coloque mina #" << (player.mines.size() + 1) << "\n";
        std::cout << "Ingrese coordenada X (1-" << maxX << "): ";
        std::cin >> x;
        std::cout << "Ingrese coordenada Y (1-" << maxY << "): ";
        std::cin >> y;

        // valida que esté dentro del tablero
        if (x < 1 || x > maxX || y < 1 || y > maxY) {
            std::cout << "Coordenadas fuera del tablero. Intente de nuevo.\n";
            continue;
        }

        // valida que no haya ya una mina ahí
        bool exists = false;
        for (size_t i = 0; i < player.mines.size(); i++) {
            if (player.mines[i].cell.x == x && player.mines[i].cell.y == y) {
                exists = true;
                break;
            }
        }
        if (exists) {
            std::cout << "Ya hay una mina en esa celda. Intente otra.\n";
            continue;
        }

        game::Mine newMine;
        newMine.cell.x = x;
        newMine.cell.y = y;
        player.mines.push_back(newMine);
    }
}//lo quiero poner en el init*/
// pide y valida un valor para filas o columnas
/*int getBoardDimension(const std::string& axisName) {
    int size = 0;
    std::cout << "Ingrese cantidad de " << axisName << " (entre 25 y 50): ";
    std::cin >> size;
    while (!game::rangeValidation(size)) {
        std::cout << "Valor invalido. Intente de nuevo: ";
        std::cin >> size;
    }
    return size;*/
//}//deinicio

//  pide y valida la cantidad de minas
/*int getMineCount() {
    int count = 0;
    std::cout << "Ingrese cantidad de minas (entre 3 y 8): ";
    std::cin >> count;
    while (!game::minesValidation(count)) {
        std::cout << "Cantidad invalida. Intente de nuevo: ";
        std::cin >> count;
    }
    return count;
}*/
// de inicio

// imprime la configuracion inicial
/*
void printGameSetup(int rows, int columns, int mines) {
    std::cout << "Configuracion completada:\n";
    std::cout << "Tablero de " << rows << " filas x " << columns << " columnas\n";
    std::cout << "Cada jugador tiene " << mines << " minas por turno\n";
}

// imprime minas de un jugador
void printPlayerMines(const Player& player, int playerNumber) {
    std::cout << "\nMinas del Jugador " << playerNumber << ":\n";
    for (size_t i = 0; i < player.mines.size(); ++i) {
        std::cout << "Mina #" << i + 1 << ": (" << player.mines[i].cell.x << "," << player.mines[i].cell.y << ")\n";
    }
}*/

// tengo ganas de usar el patron state para el estado de las celdas mas que para el juego en si
// en plan, las celdas necesitan tener un estado que me informe si las celdas estan libres, deshabilitadas o con alguna mina o algo asi

int main()

{
    //prueba 3
//prueba 2

    int columns = Init::getBoardDimension("columnas");
    int rows = Init::getBoardDimension("filas");
    int mines = Init::getMineCount();

    Board board;
    board.axisX = Init::initializeAxis(columns);
    board.axisY = Init::initializeAxis(rows);

    Player player1;
    Player player2;
    player1.remainingMines = mines;
    player2.remainingMines = mines;

    Init::printGameSetup(rows, columns, mines);
    Init::initializeGrid(board);

    std::cout << "\nJugador 1 coloque sus minas:\n";
    Init::placeMines(player1, mines, columns, rows);

    std::cout << "\nJugador 2 coloque sus minas:\n";
    Init::placeMines(player2, mines, columns, rows);

    Init::printPlayerMines(player1, 1);
    std::cout << "\nTablero Jugador 1:\n";
    //BoardUtils::printBoard(board);
    BoardUtils::printBoardPerPlayer(board, player1);

    Init::printPlayerMines(player2, 2);
    std::cout << "\nTablero Jugador 2:\n";
    //BoardUtils::printBoard(board);
    BoardUtils::printBoardPerPlayer(board, player2);


    return 0;
}