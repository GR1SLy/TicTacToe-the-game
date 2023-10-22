#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "AI.hpp"
using namespace std;
#pragma once

class game
{
public:
    game();
    ~game();
    void setmove(const int i, const int j, const int n); // Put O or X in position
    int get_Oscore();
    int get_Xscore();
    bool checkwinner(const int n); // Check 3 in line for X or O
    static int get_game_score(const int n);
    bool show_playground(); // Show positions and visualization of the game (O an X)
    void show_valid_moves(); // Show where we can put O or X
    void visualize(); // Output by visual X and O
    const int get_playground_cell(const int x, const int y);
    friend bool AI::choosemove(game& game);
    friend bool gamer::choosemove(game& game);
    

private:
    static int Xscore;
    static int Oscore;
    short int playground[3][3]; //0 - empty, 1 - O, 2 - X.
    
};

#endif