#ifndef GAMER_H
#define GAMER_H
#pragma once

#include "game.hpp"

class gamer
{
public:
    gamer();
    ~gamer();
    virtual bool choosemove(game& game); // Enter move by valid moves and return false if number is incorrect
    bool choosemove(game& game, const int n); // Enter move by valid moves and return false if number is incorrect with n for debug without cin
    int get_movex();
    int get_movey();
    char get_OX();   // Get playing O or X
    int get_score();
    bool select_OX(); //Select O or X for gamer and return true if entered symbol is valid NEED REWORK

protected:
    int score;
    int movex;
    int movey;
    static int ChooseforOX; // Even - X, Odd - O
    char ox;
};

#endif