#include "GameState.h"

#include <iostream>
#include <vector>

using namespace std;

GameState::GameState(int initP) {
    currP = initP;
    board.resize(9);
    cout << "GameState initialized!" << endl;
}

vector<int> GameState::GetBoard() {
    return board;
}

vector<int> GameState::GetEmptySpots(vector<int> board) {
    vector<int> emptySpots;

    for(vector<int>::iterator i = board.begin(); i != board.end(); i++) {
        if((*i) == 0) {
            emptySpots.push_back(i - board.begin());
        }
    }

    return emptySpots;
}

bool GameState::PlayerWins(int player, vector<int> board) {
    return ((board.at(0) == player && board.at(1) == player && board.at(2) == player) ||
            (board.at(3) == player && board.at(4) == player && board.at(5) == player) ||
            (board.at(6) == player && board.at(7) == player && board.at(8) == player) ||
            (board.at(0) == player && board.at(3) == player && board.at(6) == player) || 
            (board.at(1) == player && board.at(4) == player && board.at(7) == player) ||
            (board.at(2) == player && board.at(5) == player && board.at(8) == player) ||
            (board.at(0) == player && board.at(5) == player && board.at(8) == player) ||
            (board.at(2) == player && board.at(4) == player && board.at(6) == player));
}

bool GameState::IsDraw() {
    vector<int> emptySpots = GetEmptySpots(board);
    return emptySpots.empty();
}

bool GameState::GameOver() {
    return (PlayerWins(p1, board) || PlayerWins(p2, board) || IsDraw());
}

void GameState::MakeMove(int index) {
    board.at(index) = currP;

    if(currP == 1) {
        currP = 2;
    }
    else {
        currP = 1;
    }
}

int GameState::GetP1() {
    return p1;
}

int GameState::GetP2() {
    return p2;
}

int GameState::AIBestMove() {
    vector<int> emptySpots = GetEmptySpots(board);
    vector<int> moveScores = GetMoveScores(board, currP, currP);
    return emptySpots.at(GetMaxIndex(moveScores));
}

vector<int> GameState::GetMoveScores(vector<int> board, int currPlayer, int origPlayer) {
    vector<int> emptySpots = GetEmptySpots(board);
    vector<int> moveScores;
 
    if(PlayerWins(currPlayer, board) && currPlayer == origPlayer) {
        moveScores.push_back(1);
        return moveScores; 
    }
    else if(PlayerWins(currPlayer, board) && currPlayer != origPlayer) {
        moveScores.push_back(-1);
        return moveScores;
    } 
    else if(emptySpots.size() == 0) {
        moveScores.push_back(0);
        return moveScores;
    }

    for(vector<int>::iterator i = emptySpots.begin(); i != emptySpots.end(); i++) {
        board.at((*i)) = currPlayer; 

        int score;
        if(currPlayer == 1) {
            score = GetMoveScores(board, 2, origPlayer).at(0);
        }
        else if(currPlayer == 2) {
            score = GetMoveScores(board, 1, origPlayer).at(0);
        }

        board.at((*i)) = 0;

        moveScores.push_back(score);
    }

    return moveScores;

}

int GameState::GetMaxIndex(vector<int> scores) {
    int max = scores.at(0);
    int maxIndex = 0;

    for(vector<int>::iterator i = scores.begin(); i != scores.end(); i++) {
        if((*i) > max) {
            max = (*i);
            maxIndex = i - scores.begin();
        }
    }

    return maxIndex;
}

int GameState::GetMinIndex(vector<int> scores) {
    int min = scores.at(0);
    int minIndex = 0;

    for(vector<int>::iterator i = scores.begin(); i != scores.end(); i++) {
        if((*i) < min) {
            min = (*i);
            minIndex = i - scores.begin();
        }
    }

    return minIndex;
}

void GameState::PrintBoard() {
    int positionCounter = 1;
    cout << endl;
    for(vector<int>::iterator i = board.begin(); i != board.end(); i++) {        
        
        cout << (*i);

        if(positionCounter == 3) {
            cout << endl;
            positionCounter = 1;
        }
        else {
            cout << " | ";
            positionCounter++;
        }
    }
    cout << endl;
}

bool GameState::IsValidMove(int move) {
    return board.at(move) == 0;
}

void GameState::RequestMove() {
    int move;
    cout << "Make your move! (type a number 1-9 top left descending): ";
    cin >> move;

    if(IsValidMove(move - 1)) {
        this->MakeMove(move - 1);
    }
    else {
        cout << "Invalid Move! Please enter your move again!" << endl;
        RequestMove();
    }
}
