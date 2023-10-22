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
    void setmove(const int i, const int j, const int OX); // Put O or X in position of OX
    int get_Oscore();
    int get_Xscore();
    static int get_game_score(const int OX);
    bool show_playground(const int OX); // Show positions and visualization of the game (O an X) and return true if gamer won the game
    bool show_valid_moves(); // Show where we can put O or X and return true if there are empty cells or false if not
    void visualize(); // Output by visual X and O
    const int get_playground_cell(const int x, const int y);
    

private:
    bool checkwinner(const int n); // Check 3 in line for X or O
    static int Xscore;
    static int Oscore;
    short int playground[3][3]; //0 - empty, 1 - O, 2 - X.
    
};

#endif