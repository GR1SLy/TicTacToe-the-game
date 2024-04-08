#ifndef AI_H
#define AI_H
#pragma once

#include <iostream>
using namespace std;
#include "gamer.hpp"

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