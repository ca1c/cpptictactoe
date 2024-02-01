#include "GameState.h"
#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 9;

int main() {

    int playerSelection;
    int computerSelection;
    cout << "Welcome to TicTacToe!" << endl;
    cout << "Would you like to play X or O? (1 for x, 2 for o): ";
    cin >> playerSelection;

    computerSelection = playerSelection == 1 ? 2 : 1;

    GameState gameState = GameState(playerSelection);

    cout << "Game Started!" << endl;

    while(!gameState.GameOver()) {
        gameState.PrintBoard();
        gameState.RequestMove();
        if(!gameState.GameOver()) {
            gameState.MakeMove(gameState.AIBestMove());
            gameState.PrintBoard();
            cout << "Computer Made Move!"<< endl;
        }
        else {
            gameState.PrintBoard();
        }
    }

    if(gameState.PlayerWins(playerSelection, gameState.GetBoard())) {
        cout << endl;
        cout << "You Win!" << endl;
        cout << endl;
    }
    else if(gameState.PlayerWins(computerSelection, gameState.GetBoard())){
        cout << endl;
        cout << "Computer Wins!" << endl;
        cout << endl;
    }
    else {
        cout << endl;
        cout << "Draw!" << endl;
        cout << endl;
    }


    return 0;
}











