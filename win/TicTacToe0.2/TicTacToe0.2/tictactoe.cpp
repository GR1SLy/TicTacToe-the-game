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

Day 3:


...............................................

*/


#include <iostream>
using namespace std;
#include "game.h"
#include "gamer.h"
#include "AI.h"
//#define DEBUG

void oneplayer()
{
    gamer gamer1;
    AI gamer2;
    game game1;
    gamer2.set_difficulty();
    while (true)
    {
        if (game1.show_playground())
        {
            cout << "Moves left! It is draw!" << endl;
            break;
        }
        cout << endl;
        game1.show_valid_moves();
        cout << endl;
    labelfail1:
        if (!gamer1.choosemove(game1)) goto labelfail1;
        game1.setmove(gamer1.get_movex(), gamer1.get_movey(), gamer1.get_OX());
        if (game1.checkwinner(gamer1.get_OX()))
        {
            system("clear");
            game1.show_playground();
            cout << "You are the winner!" << endl;
            break;
        }
        cout << endl;
        system("clear");



        if (game1.show_playground())
        {
            cout << "Moves left! It is draw!" << endl;
            break;
        }
        cout << endl;
        game1.show_valid_moves();
        cout << endl;
    labelfail2:
        if (!gamer2.choosemove(game1)) goto labelfail2;
        game1.setmove(gamer2.get_movex(), gamer2.get_movey(), gamer2.get_OX());
        if (game1.checkwinner(gamer2.get_OX()))
        {
            system("clear");
            game1.show_playground();
            cout << "AI is the winner!" << endl;
            break;
        }
        cout << endl;
        system("clear");
    }
    cout << endl;


    cout << "Your score is: " << gamer1.get_score() << endl;
    cout << "AI score is: " << gamer2.get_score() << endl;
}




void twoplayers()
{
    gamer gamer1, gamer2;
    game game1;
    while (true)
    {
        if (game1.show_playground())
        {
            cout << "Moves left! It is draw!" << endl;
            break;
        }
        cout << endl;
        game1.show_valid_moves();
        cout << endl;
    labelfail1:
        if (!gamer1.choosemove(game1)) goto labelfail1;
        game1.setmove(gamer1.get_movex(), gamer1.get_movey(), gamer1.get_OX());
        if (game1.checkwinner(gamer1.get_OX()))
        {
            system("clear");
            game1.show_playground();
            cout << "Gamer 1 is the winner!" << endl;
            break;
        }
        cout << endl;
        system("clear");



        if (game1.show_playground())
        {
            cout << "Moves left! It is draw!" << endl;
            break;
        }
        cout << endl;
        game1.show_valid_moves();
        cout << endl;
    labelfail2:
        if (!gamer2.choosemove(game1)) goto labelfail2;
        game1.setmove(gamer2.get_movex(), gamer2.get_movey(), gamer2.get_OX());
        if (game1.checkwinner(gamer2.get_OX()))
        {
            system("clear");
            game1.show_playground();
            cout << "Gamer 2 is the winner!" << endl;
            break;
        }
        cout << endl;
        system("clear");
    }
    cout << endl;


    cout << "Gamer 1 score is: " << gamer1.get_score() << endl;
    cout << "Gamer 2 score is: " << gamer2.get_score() << endl;
}




int main()
{

#ifdef DEBUG
    gamer gamer1;
    AI gamer2;
    game game1;

    int n = 5;
    gamer1.choosemove(game1, n);
    game1.setmove(gamer1.get_movex(), gamer1.get_movey(), gamer1.get_OX());
    if (game1.show_playground())
    {
        return 0;
    }
    gamer2.choosemove(game1);
    game1.setmove(gamer2.get_movex(), gamer2.get_movey(), gamer2.get_OX());
    game1.show_playground();
#endif


#ifndef DEBUG

    int k;
    int n;
labelselect:
    cout << "Select game mode:\n1:\tOne player\n2:\tTwo players\nEnter a number: ";
    cin >> k;
labelreplay:
    if (k == 1) oneplayer();
    else if (k == 2) twoplayers();
    else
    {
        cout << "Enter correct number!" << endl;
        goto labelselect;
    }



    cout << "If you want to replay the game - enter 1 or any other to leave: ";
    cin >> n;
    if (n == 1) goto labelreplay;
    else
    {
        cout << "Leaving..........." << endl;
        system("pause");
    }

#endif

    return 0;
}