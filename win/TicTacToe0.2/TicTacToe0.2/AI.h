//AI.h
#ifndef AI_H
#define AI_H

#include <iostream>
using namespace std;
#include "gamer.h"
#include "game.h"
#pragma once

//class game;
//class gamer;

class AI : public gamer
{
public:
    AI();
    ~AI();
    bool choosemove(game& game) override;
    void set_difficulty();

private:
    int difficulty;

};

#endif