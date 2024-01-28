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
        vector<int> GetEmptySpots();
        bool PlayerWins(int player);
        void MakeMove(int index);
        int GetP1();
        int GetP2();
};

#endif
