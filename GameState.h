#ifndef GAMESTATEH
#define GAMESTATEH

#include <iostream>
#include <vector>

using namespace std;

class GameState {
    private:
        static const int p1 = 1;
        static const int p2 = 2;
        int currP = 1;
        vector<int> board;
    public:
        GameState(int initP);
        vector<int> GetBoard();
        vector<int> GetEmptySpots(vector<int> board);
        bool PlayerWins(int player, vector<int> board);
        void MakeMove(int index);
        int GetP1();
        int GetP2();
        int AIBestMove();
        vector<int> GetMoveScores(vector<int> board, int currPlayer, int origPlayer);
        int GetMaxIndex(vector<int> scores);
        int GetMinIndex(vector<int> scores);
};

#endif
