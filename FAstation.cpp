/*****************************************************************************
 * Class name:  FAstation
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: A fighter can recover in this zone.
*****************************************************************************/
#include "FAstation.hpp"

/*****************************************************************************
 * Description: Default constructor sets variables by default.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
FAstation::FAstation() : Space("First Aid Station")
{
}

/*****************************************************************************
 * Description: The player can recover 100% HP.
 * Arguments:   the pointer of the fighter
 * Returns:     None
*****************************************************************************/
void FAstation::event(Fighter* player)
{
    cout << "What do you want to do?" << endl;
    cout << "1. Get medical service" << endl;
    cout << "2. Leave this zone" << endl;

    int reply = 0;
    do {
        reply = validation();
        if (reply != 1 && reply != 2)
        {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (reply != 1 && reply != 2);

    if (reply == 1)
    {
        int move = player->getAction();
        if (move > 0)
        {
            player->setHP(100); //HP recovers
            int blood = player->getHP();
            cout << "Your HP: " << blood << endl;
            --move; //action - 1
            player->setAction(move);
        }
        else
        {
            cout << "Time is not enough for today." << endl;
        }
    }
}
