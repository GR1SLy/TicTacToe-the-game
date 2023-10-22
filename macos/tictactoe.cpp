/*
...............DEVELOPMENT DIARY...............

Day 1: 18.10.23: Created game with other gamer 
and first cycle of game loop 
(game.h, gamer.h, tictactoe.cpp).

Plans: add AI gamer.
...............................................

Day 2: 19.10.23: Added AI gamer playing with 
first gamer and created 3 levels of diddiculty 
(random, defence, attach+defence).
Added one or two players selection and replay 
function.

Plans: optimize algorithm for AI gamer,
add complete menu, naming gamers before game.
...............................................

Day 3: 23.10.23: Changed amount of players 
selection by dynamic storage. Changed methods
of game class to use less lines in main file.
Uploaded project in git repository.

Plans: the same thing.
...............................................

Day 4:


...............................................

*/


#include <iostream>
using namespace std;
#include "game.cpp"
#include "gamer.cpp"
#include "AI.cpp"

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
        gamer2 = new AI;
    }
    else if (k == 2)
    {
        gamer1 = new gamer;
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

    
    return 0;
}