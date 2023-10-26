#include "game.hpp"
//#define DEBUG
int game::Oscore = 0;
int game::Xscore = 0;

game::game()
{
    for (int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            playground[i][j] = OX::empty;
        }
    }
}

game::~game()
{
    for (int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            playground[i][j] = OX::empty;
        }
    }
}

void game::setmove(const int x, const int y, const char ox)
{
    if (playground[x][y] == OX::empty) playground[x][y] = ox;
    else cout << "ERROR::The cell is not empty!";
}

int game::get_Oscore() 
{
    return Oscore;
}

int game::get_Xscore() 
{
    return Xscore;
}

bool game::checkwinner(const char ox) 
{
    // Run for lines and check 3 in line
    for (int i = 0; i < 3; i++)
    {
        if (playground[i][0] == ox) 
        {
            if (playground[i][1] == ox)
            {
                if (playground[i][2] == ox)
                {
                    if (ox == OX::O) Oscore++;
                    else Xscore++;
                    return true;
                }
                else break;
            }
        }
        // Run for column and check 3 in line
        if (playground[0][i] == ox) 
        {
            if (playground[1][i] == ox)
            {
                if (playground[2][i] == ox)
                {
                    if (ox == OX::O) Oscore++;
                    else Xscore++;
                    return true;
                }
                else break;
            }
        }
    }
    // Run for diagonals
    bool winner = true;
    for (int i = 0; i < 3; i++)
    {
        if (playground[i][i] != ox)
        {
            for (int i = 0; i < 3; i++)
            {
                if (playground[i][-i + 2] != ox)
                {
                    winner = false;
                    break;
                }
            }
        }
    }
    
    if (winner) if (ox == OX::O) Oscore++;
                else Xscore++;
    return winner;
}

int game::get_game_score(const char ox) 
{
    if (ox == OX::O) return Oscore;
    else if (ox == OX::X) return Xscore;
    return -1;
}

bool game::show_playground(const char ox)
{
    #ifdef DEBUG
    cout << "PLAYGROUND:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << playground[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
    #endif
    this->visualize();
    return this->checkwinner(ox);
    
}

bool game::show_valid_moves()
{
    cout << "Valid moves:\nEnter a number where to put your move:" << endl;
    int num = 0;
    bool empty = false;
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ++num;
            if (playground[i][j] == OX::empty) 
            {
                cout << num << "\t";
                empty = true;
            }
            else cout << " \t";
        }
        cout << endl;
    }
    return empty;   
}

void game::visualize()
{
    string X[5];
    X[0] = "0   0     ";
    X[1] = " 0 0      ";
    X[2] = "  0       ";
    X[3] = X[1];
    X[4] = X[0];
    string O[5];
    O[0] = " 000      ";
    O[1] = "0   0     ";
    O[3] = O[2] = O[1];
    O[4] = O[0];
    string empty[5];
    for (int i = 0; i < 5; i++)
    {
        empty[i] = "          ";
    }
    empty[2] = "*****     ";

    for (int k = 0; k < 3; k++)
    {
        string line[5];
        for (int i = 0; i < 5; i++) 
        {
            line[i] = "";
        }

        for (int i = 0; i < 5; i++) 
        {
            for (int j = 0; j < 3; j++)
            {
            if (playground[k][j] == OX::empty) line[i] += empty[i];
            else if (playground[k][j] == OX::O) line[i] += O[i];
            else if (playground[k][j] == OX::X) line[i] += X[i];
            }
        }

        for (int i = 0; i < 5; i++)
        {
            cout << line[i] << endl;
        }
        cout << "                     " << endl;
    }
}

const int game::get_playground_cell(const int x, const int y)
{
    return playground[x][y];;
}
