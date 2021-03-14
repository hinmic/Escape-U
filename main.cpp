/*****************************************************************************
 * Program name: EscapeU!
 * Author:       Chi Hin Ng
 * Date:         10/12/2019
 * Description:  This is a text-based game. The background of the game will be
 *               shown in Gameplay. Gameplay is the class that is responsible
 *               for interacting with players and running the game. Space is
 *               a base class of all Space objects. Different Space objects
 *               have different options for the player to choose. The game
 *               ends if the HP of the player = 0 or 15 days passes and the
 *               mission is still not accomplished.
*****************************************************************************/
#include "Gameplay.hpp"
#include "validation.hpp"
#include <iostream>

int main()
{
    cout << "Welcome to EscapeU!" << endl;
    cout << "1. Play" << endl;
    cout << "2. Exit" << endl;
    int reply = 0;
    do {
        reply = validation();
        if (reply != 1 && reply != 2)
        {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (reply != 1 && reply != 2);

    while (reply == 1)
    {
        Gameplay game;
        game.menu();

        cout << "1. Play again" << endl;
        cout << "2. Exit" << endl;
        do {
            reply = validation();
            if (reply != 1 && reply != 2)
            {
                cout << "Invalid input. Please try again." << endl;
            }
        } while (reply != 1 && reply != 2);
    }

    return 0;
}
