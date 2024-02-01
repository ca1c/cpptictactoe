#include "GameState.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

void PlayTextBased();
void PlayGraphical();

int main() {
    // PlayTextBased();
    PlayGraphical();

    return 0;
}

void PlayTextBased() {
    int playerSelection;
    int computerSelection;
    cout << "Welcome to TicTacToe!" << endl;
    while(playerSelection != 1 && playerSelection != 2) {
        cout << "Would you like to play X or O? (1 for x, 2 for o): ";
        cin >> playerSelection;

        if(playerSelection != 1 || playerSelection != 2) {
            cout << "Invalid player selection..." << endl;
        }
    }

    computerSelection = playerSelection == 1 ? 2 : 1;

    GameState gameState = GameState(playerSelection);

    cout << "Game Started!" << endl;

    while(!gameState.GameOver()) {
        gameState.PrintBoard();
        gameState.RequestMove();
        if(!gameState.GameOver()) {
            gameState.MakeMove(gameState.AIBestMove(gameState.GetBoard(), computerSelection)[1]);
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
}

void PlayGraphical() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML tictactoe");
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        window.display();
    }
}











