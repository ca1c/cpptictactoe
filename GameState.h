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
        vector<int> GetEmptySpots(vector<int> newBoard);
        bool PlayerWins(int player, vector<int> newBoard);
        bool IsDraw();
        bool GameOver();
        void MakeMove(int index);
        int GetP1();
        int GetP2();
        vector<int> AIBestMove(vector<int> newBoard, int player);
        void PrintBoard();
        bool IsValidMove(int move);
        void RequestMove();
};

#endif
