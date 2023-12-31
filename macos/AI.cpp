#include "AI.hpp"
AI::AI():gamer()
{
    // if (ChooseforOX % 2 == 0) OX = 2;
    // else OX = 1;
    // movex = 0;
    // movey = 0;
    // score = 0;
    int n;
    cout << "Choose difficulty for AI:\n1:\tEasy\n2:\tHard\n3:\tReally Hard\nEnter a number: ";
    cin >> n;
    if (n > 0 && n < 4) difficulty = n;
}

AI::~AI()
{
}

bool AI::choosemove(game& game)
{   if (difficulty == 1)
    {
        // Put in random cell
    labelrand:
        do
        {
            srand(time(NULL));
            int random = rand() % 10;
            switch (random)
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
        }
        while (game.get_playground_cell(movex, movey) != 0);
    }
    else if (difficulty == 2)
    {
        // Check lines for defence (OOX)/(OXO)/(XOO)
    labeldef:
        for (int i = 0; i < 3; i++)
        {
            if (game.get_playground_cell(i, 0) != OX && game.get_playground_cell(i, 0) != 0)
            {
                if (game.get_playground_cell(i, 1) != OX && game.get_playground_cell(i, 1) != 0)
                {
                    if (game.get_playground_cell(i, 2) != OX && game.get_playground_cell(i, 2) == 0)
                    {
                        movex = i;
                        movey = 2;
                        return true;
                    }
                }
                else if (game.get_playground_cell(i, 1) != OX && game.get_playground_cell(i, 1) == 0)
                {
                    if (game.get_playground_cell(i, 2) != OX && game.get_playground_cell(i, 2) != 0)
                    {
                        movex = i;
                        movey = 1;
                        return true;
                    }
                }
            }
            else if (game.get_playground_cell(i, 0) != OX && game.get_playground_cell(i, 0) == 0)
            {
                if (game.get_playground_cell(i, 1) != OX && game.get_playground_cell(i, 1) != 0)
                {
                    if (game.get_playground_cell(i, 2) != OX && game.get_playground_cell(i, 2) != 0)
                    {
                        movex = i;
                        movey = 0;
                        return true;
                    }
                }
            }
        }
        // Check for column (rotated line check)
        for (int i = 0; i < 3; i++)
        {
            if (game.get_playground_cell(0, i) != OX && game.get_playground_cell(0, i) != 0)
            {
                if (game.get_playground_cell(1, i) != OX && game.get_playground_cell(1, i) != 0)
                {
                    if (game.get_playground_cell(2, i) != OX && game.get_playground_cell(2, i) == 0)
                    {
                        movex = 2;
                        movey = i;
                        return true;
                    }
                }
                else if (game.get_playground_cell(1, i) != OX && game.get_playground_cell(1, i) == 0)
                {
                    if (game.get_playground_cell(2, i) != OX && game.get_playground_cell(2, i) != 0)
                    {
                        movex = 1;
                        movey = i;
                        return true;
                    }
                }
            }
            else if (game.get_playground_cell(0, i) != OX && game.get_playground_cell(0, i) == 0)
            {
                if (game.get_playground_cell(1, i) != OX && game.get_playground_cell(1, i) != 0)
                {
                    if (game.get_playground_cell(2, i) != OX && game.get_playground_cell(2, i) != 0)
                    {
                        movex = 0;
                        movey = i;
                        return true;
                    }
                }
            }
        }
        // Check for diagnals
        if (game.get_playground_cell(0, 0) != OX && game.get_playground_cell(0, 0) != 0)
        {
            if (game.get_playground_cell(1,1) != OX && game.get_playground_cell(1, 1) != 0)
            {
                if (game.get_playground_cell(2, 2) != OX && game.get_playground_cell(2, 2) == 0)
                {
                    movex = 2;
                    movey = 2;
                    return true;
                }
            }
            else if (game.get_playground_cell(1, 1) != OX && game.get_playground_cell(1, 1) == 0)
            {
                if (game.get_playground_cell(2, 2) != OX && game.get_playground_cell(2, 2) != 0)
                {
                    movex = 1;
                    movey = 1;
                    return true;
                }
            }
        }
        else if (game.get_playground_cell(0, 0) != OX && game.get_playground_cell(0, 0) == 0)
        {
            if (game.get_playground_cell(1,1) != OX && game.get_playground_cell(1, 1) != 0)
            {
                if (game.get_playground_cell(2, 2) != OX && game.get_playground_cell(2, 2) != 0)
                {
                    movex = 0;
                    movey = 0;
                    return true;
                }
            }
        }
        // Other diagonal
        if (game.get_playground_cell(0, 2) != OX && game.get_playground_cell(0, 2) != 0)
        {
            if (game.get_playground_cell(1,1) != OX && game.get_playground_cell(1, 1) != 0)
            {
                if (game.get_playground_cell(2, 0) != OX && game.get_playground_cell(2, 0) == 0)
                {
                    movex = 2;
                    movey = 0;
                    return true;
                }
            }
            else if (game.get_playground_cell(1, 1) != OX && game.get_playground_cell(1, 1) == 0)
            {
                if (game.get_playground_cell(2, 0) != OX && game.get_playground_cell(2, 0) != 0)
                {
                    movex = 1;
                    movey = 1;
                    return true;
                }
            }
        }
        else if (game.get_playground_cell(0, 2) != OX && game.get_playground_cell(0, 2) == 0)
        {
            if (game.get_playground_cell(1,1) != OX && game.get_playground_cell(1, 1) != 0)
            {
                if (game.get_playground_cell(2, 0) != OX && game.get_playground_cell(2, 0) != 0)
                {
                    movex = 0;
                    movey = 2;
                    return true;
                }
            }
        }

        // If defence was not needed put random cell
        goto labelrand;
    }
    else if (difficulty == 3)
    {
        // Firstly check if bot can put 3 in line
        // Check diagonal
        if (game.get_playground_cell(0, 0) == OX)
        {
            if (game.get_playground_cell(1,1) == OX)
            {
                if (game.get_playground_cell(2, 2) == 0)
                {
                    movex = 2;
                    movey = 2;
                    return true;
                }
            }
            else if (game.get_playground_cell(1, 1) == 0)
            {
                if (game.get_playground_cell(2, 2) == OX)
                {
                    movex = 1;
                    movey = 1;
                    return true;
                }
            }
        }
        else if (game.get_playground_cell(0, 0) == 0)
        {
            if (game.get_playground_cell(1,1) == OX)
            {
                if (game.get_playground_cell(2, 2) == OX)
                {
                    movex = 0;
                    movey = 0;
                    return true;
                }
            }
        }
        // Other diagonal
        if (game.get_playground_cell(0, 2) == OX )
        {
            if (game.get_playground_cell(1,1) == OX)
            {
                if (game.get_playground_cell(2, 0) == 0)
                {
                    movex = 2;
                    movey = 0;
                    return true;
                }
            }
            else if (game.get_playground_cell(1, 1) == 0)
            {
                if (game.get_playground_cell(2, 0) == OX)
                {
                    movex = 1;
                    movey = 1;
                    return true;
                }
            }
        }
        else if (game.get_playground_cell(0, 2) == 0)
        {
            if (game.get_playground_cell(1,1) == OX)
            {
                if (game.get_playground_cell(2, 0) == OX)
                {
                    movex = 0;
                    movey = 2;
                    return true;
                }
            }
        }
        // Check lines for win
        for (int i = 0; i < 3; i++)
        {
            if (game.get_playground_cell(i, 0) == OX)
            {
                if (game.get_playground_cell(i, 1) == OX)
                {
                    if (game.get_playground_cell(i, 2) == 0)
                    {
                        movex = i;
                        movey = 2;
                        return true;
                    }
                }
                else if (game.get_playground_cell(i, 1) == 0)
                {
                    if (game.get_playground_cell(i, 2) == OX)
                    {
                        movex = i;
                        movey = 1;
                        return true;
                    }
                }
            }
            else if (game.get_playground_cell(i, 0) == 0)
            {
                if (game.get_playground_cell(i, 1) == OX)
                {
                    if (game.get_playground_cell(i, 2) == OX)
                    {
                        movex = i;
                        movey = 0;
                        return true;
                    }
                }
            }
        }
        // Check columns for win
        for (int i = 0; i < 3; i++)
        {
            if (game.get_playground_cell(0, i) == OX)
            {
                if (game.get_playground_cell(1, i) == OX)
                {
                    if (game.get_playground_cell(2, i) == 0)
                    {
                        movex = 2;
                        movey = i;
                        return true;
                    }
                }
                else if (game.get_playground_cell(1, i) == 0)
                {
                    if (game.get_playground_cell(2, i) == OX)
                    {
                        movex = 1;
                        movey = i;
                        return true;
                    }
                }
            }
            else if (game.get_playground_cell(0, i) == 0)
            {
                if (game.get_playground_cell(1, i) == OX)
                {
                    if (game.get_playground_cell(2, i) == OX)
                    {
                        movex = 0;
                        movey = i;
                        return true;
                    }
                }
            }
        }
        // If there no ways to win - go to defence
        goto labeldef;
    }
    return true;
}

/*
*            *
  *        *
    *    *
*/


// Лучше сначала сделать проверку нападения есть ли у бота три в ряд а потом уже чекать защиту
/*  
Сначала играем в оборону: ищем есть ли где то потенциально выиграшная ситуация игрока - тогда ставим знак
Если оборона не нужна, начинаем составлять свою линию с запоминанием ходов и продолжением отталкиваясь от прошлого
чтобы поставить нужный ход - ретурнить тру
*/

void AI::set_difficulty()
{
    int n;
    cout << "Choose difficulty for AI:\n1:\tEasy\n2:\tHard\n3:\tReally Hard\nEnter a number: ";
    cin >> n;
    if (n > 0 && n < 4) difficulty = n;
}
