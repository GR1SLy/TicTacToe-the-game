#include <iostream>
using namespace std;
#include "game.hpp"
#include "gamer.hpp"
#include "AI.hpp"

int main() 
{
    game *game1 = new game;
    gamer *gamer1, *gamer2;


    int k;
labelselect:
    cout << "Select game mode:\n1:\tOne player\n2:\tTwo players\nEnter a number: ";
    cin >> k;
labelreplay:
    if (k == 1) 
    {
        gamer1 = new gamer;
        //if (!gamer1->select_OX()) goto labelreplay;
        gamer2 = new AI;
    }
    else if (k == 2)
    {
        gamer1 = new gamer;
        //if (!gamer1->select_OX()) goto labelreplay;
        gamer2 = new gamer;
    }
    else 
    {
        cout << "Enter correct number!" << endl;
        goto labelselect;
    }



    while (true)
    {
        game1->show_playground(1);
        game1->show_valid_moves();
        while (true)
        {
        gamer1fail:
            if (!gamer1->choosemove(*game1)) goto gamer1fail;
            game1->setmove(gamer1->get_movex(), gamer1->get_movey(), gamer1->get_OX());
            system("clear");
            if (game1->show_playground(gamer1->get_OX()))
            {
                cout << "Gamer 1 is the winner!" << endl;
                break;
            }
            if (!game1->show_valid_moves())
            {
                cout << "It is a draw! Moves left!" << endl;
                break;
            }

        gamer2fail:
            if (!gamer2->choosemove(*game1)) goto gamer2fail;
            game1->setmove(gamer2->get_movex(), gamer2->get_movey(), gamer2->get_OX());
            system("clear");
            if (game1->show_playground(gamer2->get_OX()))
            {
                cout << "Gamer 2 is the winner!" << endl;
                break;
            }
            if (!game1->show_valid_moves())
            {
                cout << "It is a draw! Moves left!" << endl;
                break;
            }
        }
        cout << "If you want to replay the game - enter 1 or any other to leave: ";
        cin >> k;
        if (k == 1)
        {
            delete game1;
            game1 = new game;
        }
        else
        {
            cout << "Leaving..........." << endl;
            break;
        }
    }

    delete game1;
    delete gamer1;
    delete gamer2;

    
    return 0;
}