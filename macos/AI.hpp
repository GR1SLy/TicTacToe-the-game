#ifndef AI_H
#define AI_H

#include <iostream>
using namespace std;
#include "gamer.hpp"
#include "game.hpp"
#pragma once

class game;

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