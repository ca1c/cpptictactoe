#ifndef GAMESTATEH
#define GAMESTATEH

#include <iostream>
#include <vector>

using namespace std;

class GameState {
    private:
        static const int p1 = 1;
        static const int p2 = 2;
        vector<int> board(9);
    public:
        GameState();
        vector<int> GetBoard();
        vector<int> GetEmptySpots();
        bool PlayerWins(int player);
        void MakeMove(int index);
}

#endif
