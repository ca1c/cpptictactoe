#include "GameState.h"

#include <iostream>
#include <vector>

using namespace std;

GameState::GameState(int initP) {
    currP = currP;
    board.resize(9);
    cout << "GameState initialized!" << endl;
}

vector<int> GameState::GetBoard() {
    return board;
}

vector<int> GameState::GetEmptySpots() {
    vector<int> emptySpots;

    for(vector<int>::iterator i = board.begin(); i != board.end(); i++) {
        if((*i) == 0) {
            emptySpots.push_back(i - board.begin());
        }
    }

    return emptySpots;
}

bool GameState::PlayerWins(int player) {
    return ((board.at(0) == player && board.at(1) == player && board.at(2) == player) ||
            (board.at(3) == player && board.at(4) == player && board.at(5) == player) ||
            (board.at(6) == player && board.at(7) == player && board.at(8) == player) ||
            (board.at(0) == player && board.at(3) == player && board.at(6) == player) ||
            (board.at(1) == player && board.at(4) == player && board.at(7) == player) ||
            (board.at(2) == player && board.at(5) == player && board.at(8) == player) ||
            (board.at(0) == player && board.at(5) == player && board.at(8) == player) ||
            (board.at(2) == player && board.at(4) == player && board.at(6) == player));
}


