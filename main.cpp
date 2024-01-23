#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 9;

vector<int> getEmptySpots(vector<int> board);
bool playerWins(int player, vector<int> board);
int minimax(vector<int> board, int currPlayer);
vector<int> getMoveScores(vector<int> board, int currPlayer);
int getMaxIndex(vector<int> scores);
int getMinIndex(vector<int> scores);

int main() {
    
    vector<int> board(9);
    
    vector<int> emptySpots = getEmptySpots(board);

    int bestMoveIndex = minimax(board, 0);

    cout << bestMoveIndex << endl;

    return 0;
}

vector<int> getEmptySpots(vector<int> board) {
    vector<int> emptySpots;
    
    for(vector<int>::iterator i = board.begin(); i != board.end(); i++) {
        if((*i) == 0) {
            emptySpots.push_back(i - board.begin());
        }
    }

    return emptySpots;
}

bool playerWins(int player, vector<int> board) {
    return ((board.at(0) == player && board.at(1) == player && board.at(2) == player) ||
            (board.at(3) == player && board.at(4) == player && board.at(5) == player) ||
            (board.at(6) == player && board.at(7) == player && board.at(8) == player) ||
            (board.at(0) == player && board.at(3) == player && board.at(6) == player) ||
            (board.at(1) == player && board.at(4) == player && board.at(7) == player) ||
            (board.at(2) == player && board.at(5) == player && board.at(8) == player) ||
            (board.at(0) == player && board.at(5) == player && board.at(8) == player) ||
            (board.at(2) == player && board.at(4) == player && board.at(6) == player));
}

// returns the index of the best move
int minimax(vector<int> board, int currPlayer) {
    // Player 0 is the computer and player 1 is the opponent
    vector<int> emptySpots = getEmptySpots(board); 
    vector<int> moveScores = getMoveScores(board, currPlayer);

    int bestMoveIndex;
    if(currPlayer == 0) {
        return emptySpots.at(getMaxIndex(moveScores));
    }

    return emptySpots.at(getMinIndex(moveScores));
}

vector<int> getMoveScores(vector<int> board, int currPlayer) {
    vector<int> emptySpots = getEmptySpots(board);
    vector<int> moveScores;

    if(playerWins(currPlayer, board) && currPlayer == 0) {
        moveScores.push_back(1);
        return moveScores;
    }
    else if(playerWins(currPlayer, board) && currPlayer == 1) {
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
        if(currPlayer == 0) {
            score = getMoveScores(board, 1).at(0);
        }
        else if(currPlayer == 1) {
            score = getMoveScores(board, 0).at(0);
        }

        board.at((*i)) = 0;

        moveScores.push_back(score);

    }

    return moveScores;
}

int getMaxIndex(vector<int> scores) {
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

int getMinIndex(vector<int> scores) {
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












