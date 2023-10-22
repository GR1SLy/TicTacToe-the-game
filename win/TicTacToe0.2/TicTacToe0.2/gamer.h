//gamer.h
#ifndef GAMER_H
#define GAMER_H

#pragma once
#include "game.h"

//class game;
//class AI;

class gamer
{
public:
    gamer();
    ~gamer();
    //void choose_move(const string move); // Enter move like 1,2 or 1;2 or 1.2
    virtual bool choosemove(game& game); // Enter move by valid moves //nado ebanut' proverky na 0 [i][j]
    bool choosemove(game& game, const int n);
    int get_movex();
    int get_movey();
    int get_OX();   // Get playing O or X
    int get_score();

protected:
    int score;
    int movex;
    int movey;
    static int ChooseforOX; // Even - X, Odd - O
    int OX; // 1 - O, 2 - X
};

#endif