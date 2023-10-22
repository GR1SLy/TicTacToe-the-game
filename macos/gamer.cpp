#include "gamer.hpp"

int gamer::ChooseforOX = 0;

gamer::gamer()
{ 
    ++ChooseforOX;
    if (ChooseforOX % 2 == 0) OX = 2;
    else OX = 1;
    movex = 0;
    movey = 0;
    score = 0;
}

gamer::~gamer()
{
}

/* void gamer::choose_move(const string move) 
{
    movex = (int)move[0] - '0';
    movey = (int)move[2] - '0'; 
} */

bool gamer::choosemove(game& game)
{
    cout << "Gamer " << OX << "! It is your turn with ";
    if (OX == 1) cout << "O";
    else if (OX == 2) cout << "X";
    cout << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        movex = 0;
        movey = 0;
        break;
    case 2:
        movex = 0;
        movey = 1;
        break;
    case 3:
        movex = 0;
        movey = 2;
        break;
    case 4:
        movex = 1;
        movey = 0;
        break;
    case 5:
        movex = 1;
        movey = 1;
        break;
    case 6:
        movex = 1;
        movey = 2;
        break;
    case 7:
        movex = 2;
        movey = 0;
        break;
    case 8:
        movex = 2;
        movey = 1;
        break;
    case 9:
        movex = 2;
        movey = 2;
        break;
    }
    if (game.playground[movex][movey] == 0) return true;
    else
    {
        cout << "That cell is already used" << endl;
        return false;
    }
}

bool gamer::choosemove(game& game, const int n)
{
    cout << "Gamer " << OX << "! It is your turn with ";
    if (OX == 1) cout << "O";
    else if (OX == 2) cout << "X";
    cout << endl;
    switch (n)
    {
    case 1:
        movex = 0;
        movey = 0;
        break;
    case 2:
        movex = 0;
        movey = 1;
        break;
    case 3:
        movex = 0;
        movey = 2;
        break;
    case 4:
        movex = 1;
        movey = 0;
        break;
    case 5:
        movex = 1;
        movey = 1;
        break;
    case 6:
        movex = 1;
        movey = 2;
        break;
    case 7:
        movex = 2;
        movey = 0;
        break;
    case 8:
        movex = 2;
        movey = 1;
        break;
    case 9:
        movex = 2;
        movey = 2;
        break;
    }
    if (game.get_playground_cell(movex, movey) == 0) return true;
    return false;
}

int gamer::get_movex()
{
    return movex;
}

int gamer::get_movey()
{
    return movey;
}

int gamer::get_OX()
{
    return OX;
}

int gamer::get_score()
{
    score = game::get_game_score(OX);
    // cout << "Gamer " << OX << " score is: " << score << endl;
    return score;
}