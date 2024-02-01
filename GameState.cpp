#include "GameState.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

GameState::GameState(int initP) {
    currP = initP;
    board.resize(9);
    cout << "GameState initialized!" << endl;
}

vector<int> GameState::GetBoard() {
    return board;
}

vector<int> GameState::GetEmptySpots(vector<int> newBoard) {
    vector<int> emptySpots;

    for(vector<int>::iterator i = newBoard.begin(); i != newBoard.end(); i++) {
        if((*i) == 0) {
            emptySpots.push_back(i - newBoard.begin());
        }
    }

    return emptySpots;
}

bool GameState::PlayerWins(int player, vector<int> newBoard) {
    return ((newBoard.at(0) == player && newBoard.at(1) == player && newBoard.at(2) == player) ||
            (newBoard.at(3) == player && newBoard.at(4) == player && newBoard.at(5) == player) ||
            (newBoard.at(6) == player && newBoard.at(7) == player && newBoard.at(8) == player) ||
            (newBoard.at(0) == player && newBoard.at(3) == player && newBoard.at(6) == player) || 
            (newBoard.at(1) == player && newBoard.at(4) == player && newBoard.at(7) == player) ||
            (newBoard.at(2) == player && newBoard.at(5) == player && newBoard.at(8) == player) ||
            (newBoard.at(0) == player && newBoard.at(5) == player && newBoard.at(8) == player) ||
            (newBoard.at(2) == player && newBoard.at(4) == player && newBoard.at(6) == player));
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

vector<int> GameState::AIBestMove(vector<int> newBoard, int player) {
    vector<int> emptySpots = GetEmptySpots(newBoard);
    vector<int> finalMove;

    if(PlayerWins(1, newBoard)) {
        finalMove.push_back(1);
        return finalMove;
    }
    if(PlayerWins(2, newBoard)) {
        finalMove.push_back(-1);
        return finalMove;
    }
    else if(emptySpots.size() == 0) {
        finalMove.push_back(0);
        return finalMove;
    }

    vector<int> moveIndex;
    vector<int> moveScores;

    for(int i = 0; i < emptySpots.size(); i++) {
        //vector<int> boardCopy = newBoard;
        newBoard[emptySpots[i]] = player;

        int totalScore;
        if(player == 1) {
            totalScore = AIBestMove(newBoard, 2)[0];
        }
        else if(player == 2) {
            totalScore = AIBestMove(newBoard, 1)[0];
        }

        newBoard[emptySpots[i]] = 0;
        moveIndex.push_back(i);
        moveScores.push_back(totalScore);
    }

    vector<int> bestMove;

    if(player == 1) {
        int max = *max_element(moveScores.begin(), moveScores.end());
        int index = moveIndex[find(moveScores.begin(), moveScores.end(), max) - moveScores.begin()];
        bestMove.push_back(max);
        bestMove.push_back(emptySpots[index]);
    }
    else if(player == 2) {
        int min = *min_element(moveScores.begin(), moveScores.end());
        int index = moveIndex[find(moveScores.begin(), moveScores.end(), min) - moveScores.begin()];
        bestMove.push_back(min);
        bestMove.push_back(emptySpots[index]);
    }
    return bestMove;
}

void GameState::PrintBoard() {
    int positionCounter = 1;
    cout << endl;
    for(vector<int>::iterator i = board.begin(); i != board.end(); i++) {        
        
        switch((*i)) {
            case 1:
                cout << "X";
                break;
            case 2:
                cout << "O";
                break;
            default:
                cout << "_";
        }

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
