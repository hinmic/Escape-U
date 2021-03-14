/*****************************************************************************
 * Class name:  Street
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: Street is the Space that connects the Entrance and the
 *              Activity Room. A player can dig a brick in this Space.
*****************************************************************************/
#include "Street.hpp"

/*****************************************************************************
 * Description: Default constructor that calls Space constructor to set
 *              variables.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Street::Street() : Space("Street")
{
}

/*****************************************************************************
 * Description: The actions that the player may take in this Space.
 * Arguments:   a pointer to the fighter
 * Returns:     None
*****************************************************************************/
void Street::event(Fighter* player)
{
    cout << "What do you want to do?" << endl;
    cout << "1. Dig a brick" << endl;
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
        int size = player->getCap(); //get the capacity of container
        int move = player->getAction(); //get the no. of actions

        if (move > 0)
        {
            --move; //no. of actions - 1
            player->setAction(move); //update no. of actions

            if (size > 0)
            {
                player->addBack(4);
                cout << "You take a brick." << endl;
            }
            else //the container is full
            {
                string item1 = player->getFront();
                string item2 = player->getBack();

                cout << "Your bag is full." << endl;
                cout << "1. Throw " << item1 << endl;
                cout << "2. Throw " << item2 << endl;
                cout << "3. Do not take a brick" << endl;
                do {
                    reply = validation();
                    if (reply < 1 || reply > 3)
                    {
                        cout << "Invalid input. Please try again." << endl;
                    }
                } while (reply < 1 || reply > 3);

                if (reply == 1)
                {
                    player->popFront();
                    player->addFront(4);
                    cout << "You throw the " << item1 << endl;
                    cout << "You take a brick." << endl;
                }
                else if (reply == 2)
                {
                    player->popBack();
                    player->addBack(4);
                    cout << "You throw the " << item2 << endl;
                    cout << "You take a brick." << endl;
                }
            }
        }
        else
        {
            cout << "Time is not enough for today." << endl;
        }
    }
}
