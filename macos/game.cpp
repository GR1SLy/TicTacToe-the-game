#include "game.hpp"
//#define DEBUF
int game::Oscore = 0;
int game::Xscore = 0;

game::game()
{
    for (int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            playground[i][j] = 0;
        }
    }
}

game::~game()
{
    for (int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            playground[i][j] = 0;
        }
    }
}

void game::setmove(const int x, const int y, const int n)
{
    if (playground[x][y] == 0) playground[x][y] = n;
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

bool game::checkwinner(const int n) 
{
    // Run for lines and check 3 in line
    for (int i = 0; i < 3; i++)
    {
        if (playground[i][0] == n) 
        {
            if (playground[i][1] == n)
            {
                if (playground[i][2] == n)
                {
                    if (n == 1) Oscore++;
                    else Xscore++;
                    return true;
                }
                else break;
            }
        }
        // Run for column and check 3 in line
        if (playground[0][i] == n) 
        {
            if (playground[1][i] == n)
            {
                if (playground[2][i] == n)
                {
                    if (n == 1) Oscore++;
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
        if (playground[i][i] != n)
        {
            for (int i = 0; i < 3; i++)
            {
                if (playground[i][-i + 2] != n)
                {
                    winner = false;
                    break;
                }
            }
        }
    }
    
    if (winner) if (n == 1) Oscore++;
                else Xscore++;
    return winner;
}

int game::get_game_score(const int n) 
{
    if (n == 1) return Oscore;
    else if (n == 2) return Xscore;
    return -1;
}

bool game::show_playground()
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
    // Check for empty cells
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (playground[i][j] == 0) return false;
        }
    }
    return true;
}

void game::show_valid_moves()
{
    cout << "Valid moves:\nEnter a number where to put your move:" << endl;
    int num = 0;
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ++num;
            if (playground[i][j] == 0) cout << num << "\t";
            else cout << " \t";
        }
        cout << endl;
    }
    
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
            if (playground[k][j] == 0) line[i] += empty[i];
            else if (playground[k][j] == 1) line[i] += O[i];
            else if (playground[k][j] == 2) line[i] += X[i];
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
