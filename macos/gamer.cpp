#include "gamer.hpp"
//#define DEBUG

int gamer::ChooseforOX = 0;

gamer::gamer()
{ 
    ++ChooseforOX;
    if (ChooseforOX % 2 == 0) ox = OX::X;
    else ox = OX::O;
    movex = 0;
    movey = 0;
    score = 0;
}

gamer::~gamer()
{
}

bool gamer::choosemove(game& game)
{
    cout << "Gamer " << ChooseforOX << "! It is your turn with " << ox;
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
    if (game.get_playground_cell(movex, movey) == OX::empty) return true;
    else
    {
        cout << "That cell is already used" << endl;
        return false;
    }
}

#ifdef DEBUG
bool gamer::choosemove(game& game, const int n)
{
    cout << "Gamer " << ChooseforOX << "! It is your turn with " << ox;
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
    if (game.get_playground_cell(movex, movey) == OX::empty) return true;
    return false;
}
#endif

int gamer::get_movex()
{
    return movex;
}

int gamer::get_movey()
{
    return movey;
}

char gamer::get_OX()
{
    return ox;
}

int gamer::get_score()
{
    score = game::get_game_score(ox);
    // cout << "Gamer " << OX << " score is: " << score << endl;
    return score;
}

bool gamer::select_OX() // Needed rework for second gamer automatic choose
{
    cout << "Select O or X for gamer " << ChooseforOX << " (enter " << (char)OX::O << " or " << (char)OX::X << "): ";
        char ch;
        cin >> ch;
        if (ch == OX::O || ch == OX::X) ox = ch;
        else 
        {
            cout << "Invalid symbol " << ch << endl;
            return false;
        }
        return true;
}
