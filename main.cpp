#include "GameState.h"
#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 9;

int main() {

    int playerSelection;
    cout << "Welcome to TicTacToe!" << endl;
    cout << "Would you like to play X or O? (1 for x, 2 for o): ";
    cin >> playerSelection;

    GameState gameState = GameState(playerSelection);

    cout << "Game Started!" << endl;
    
    gameState.PrintBoard();

    gameState.RequestMove();

    gameState.PrintBoard();


    return 0;
}











