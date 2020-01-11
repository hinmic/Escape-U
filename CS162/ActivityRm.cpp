/*****************************************************************************
 * Class name:  ActivityRm
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: This class allow players to end a turn and start a new day. A
 *              player can also make some useful tools at this Space. This
 *              class inherits from Space.
*****************************************************************************/
#include "ActivityRm.hpp"

/*****************************************************************************
 * Description: Default constructor sets variables by default.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
ActivityRm::ActivityRm() : Space("Activity Room")
{
    turn = 0;
}

/*****************************************************************************
 * Description: Setter of turn.
 * Arguments:   the number of turns
 * Returns:     None
*****************************************************************************/
void ActivityRm::setTurn(int round)
{
    turn = round;
}

/*****************************************************************************
 * Description: Getter of turn.
 * Arguments:   None
 * Returns:     number of turns
*****************************************************************************/
int ActivityRm::getTurn()
{
    return turn;
}

/*****************************************************************************
 * Description: Provide options for the player to start a new turn and make
 *              tools.
 * Arguments:   A pointer to the fighter
 * Returns:     None
*****************************************************************************/
void ActivityRm::event(Fighter* player)
{
    cout << "What do you want to do?" << endl;
    cout << "1. Start a new day" << endl;
    cout << "2. Grab a tool" << endl;
    cout << "3. Leave this zone" << endl;

    int reply = 0;
    do {
        reply = validation();
        if (reply < 1 || reply > 3)
        {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (reply < 1 || reply > 3);

    if (reply == 1)
    {
        turn++;
        player->setAction(1);
    }
    else if (reply == 2)
    {
        cout << "Pick a tool:" << endl;
        cout << "1. Rope" << endl;
        cout << "2. Umbrella" << endl;
        cout << "3. Gas mask" << endl;

        int size = player->getCap();
        string item1 = player->getFront();
        string item2 = player->getBack();

        do {
            reply = validation();
            if (reply < 1 || reply > 3)
            {
                cout << "Invalid input. Please try again." << endl;
            }
        } while (reply < 1 || reply > 3);

        if (reply == 1)
        {
            if (size > 0)
            {
                player->addBack(1);
                cout << "You take a rope." << endl;
            }
            else
            {
                cout << "Your bag is full." << endl;
                cout << "1. Throw " << item1 << endl;
                cout << "2. Throw " << item2 << endl;
                cout << "3. Do not take a rope" << endl;

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
                    player->addFront(1);
                    cout << "You throw the " << item1 << endl;
                    cout << "You take a rope." << endl;
                }
                else if (reply == 2)
                {
                    player->popBack();
                    player->addBack(1);
                    cout << "You throw the " << item2 << endl;
                    cout << "You take a rope." << endl;
                }
            }
        }
        else if (reply == 2)
        {
            if (size > 0)
            {
                player->addBack(2);
                cout << "You take an umbrella." << endl;
            }
            else
            {
                cout << "Your bag is full." << endl;
                cout << "1. Throw " << item1 << endl;
                cout << "2. Throw " << item2 << endl;
                cout << "3. Do not take an umbrella" << endl;

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
                    player->addFront(2);
                    cout << "You throw the " << item1 << endl;
                    cout << "You take an umbrella." << endl;
                }
                else if (reply == 2)
                {
                    player->popBack();
                    player->addBack(2);
                    cout << "You throw the " << item2 << endl;
                    cout << "You take an umbrella." << endl;
                }
            }
        }
        else
        {
            if (size > 0)
            {
                player->addBack(3);
                cout << "You take a gas mask." << endl;
            }
            else
            {
                cout << "Your bag is full." << endl;
                cout << "1. Throw " << item1 << endl;
                cout << "2. Throw " << item2 << endl;
                cout << "3. Do not take a gas mask" << endl;

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
                    player->addFront(3);
                    cout << "You throw the " << item1 << endl;
                    cout << "You take a gas mask." << endl;
                }
                else if (reply == 2)
                {
                    player->popBack();
                    player->addBack(3);
                    cout << "You throw the " << item2 << endl;
                    cout << "You take a gas mask." << endl;
                }
            }
        }
    }
}
