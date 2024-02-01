#!/bin/sh

# g++ main.cpp GameState.cpp -o tictactoe

g++ -o tictactoe main.cpp GameState.cpp -lsfml-graphics -lsfml-window -lsfml-system

./tictactoe
