/*****************************************************************************
 * Class name:  Garden
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: This class helps nothing for the player to win the game,
 *              unless a special condition is met. It inherits from Space.
 *              If the player comes here with the rope, he may win the game.
*****************************************************************************/
#include "Garden.hpp"

/*****************************************************************************
 * Description: Default constructor sets variables by default.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Garden::Garden() : Space("Garden")
{
}

/*****************************************************************************
 * Description: Interact with the player to let the fighter take actions.
 * Arguments:   a pointer to the fighter
 * Returns:     None
*****************************************************************************/
void Garden::event(Fighter* player)
{
    bool escape = player->getEsp();

    cout << "There is a bridge 15m below the edge of the garden." << endl;
    cout << "What do you want to do?" << endl;
    cout << "1. Take a nap" << endl;
    cout << "2. Jump down to the bridge" << endl;
    if (escape)
    {
        cout << "3. Climb down to the bridge with the rope" << endl;
    }
    else
    {
        cout << "3. Leave this zone" << endl;
    }

    int reply = 0;
    int move = player->getAction();

    do {
        reply = validation();
        if (reply < 1 || reply > 3)
        {
            cout << "Invalid input. Pleasee try again." << endl;
        }
    } while (reply < 1 || reply > 3);

    if (reply == 1)
    {
        if (move > 0)
        {
            --move;
            player->setAction(move);
            cout << "You take a nap. Time wasted." << endl;
        }
        else
        {
            cout << "Time is not enough for today." << endl;
        }
    }
    else if (reply == 2)
    {
        player->setHP(0);
        cout << "You jump. You die." << endl;
    }
    else
    {
        if (escape)
        {
            cout << "You climb down to the bridge. The bandits discover "
                 << "your action but they are too far to stop you." << endl;
            player->setWin(true);
        }
    }
}
