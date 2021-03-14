/*****************************************************************************
 * Class name:  Entrance
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: Entrance is the exit the building. To pass this space and
 *              leave the building, the player must fight against all the
 *              Bandits. The player can exit the space to leave a fight. The
 *              game is over if the player loses and get caught by any of the
 *              Bandits.
*****************************************************************************/
#include "Entrance.hpp"

/*****************************************************************************
 * Description: Default destructor set the number of Bandits at this space.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Entrance::Entrance() : Space("Entrance")
{
    num_bandit = 10;
}

/*****************************************************************************
 * Description: Setter of num_bandit.
 * Arguments:   the number of bandits
 * Returns:     None
*****************************************************************************/
void Entrance::setNum(int num)
{
    num_bandit = num;
}

/*****************************************************************************
 * Description: Carry out the fight between Bandits and the player.
 * Arguments:   a pointer to the player's character
 * Returns:     None
*****************************************************************************/
void Entrance::event(Fighter* player)
{
    cout << "Do you want to pass this entrance?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    //Get player's decision of passing this gate
    int reply = 0;
    do {
        reply = validation();
        if (reply != 1 && reply != 2)
        {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (reply != 1 && reply != 2);

    //Start to fight the Bandits
    if (reply == 1)
    {
        int move = player->getAction();
        if (move > 0)
        {
            Bandit popo;
            int popo_HP = popo.getHP();
            int player_HP = player->getHP();

            while (num_bandit > 0)
            {
                popo.takeDamage(player->getAtk()); //player attacks
                popo_HP = popo.getHP();
                if (popo_HP <= 0)
                {
                    --num_bandit;
                    popo.setHP(100); //fight a new Bandit
                }

                if (num_bandit > 0)
                {
                    player->takeDamage(popo.getAtk()); //Bandit attacks
                    player_HP = player->getHP();
                    if (player_HP <= 0)
                    {
                        break; //player get caught, game over
                    }
                    else
                    {
                        //Chance to leave the fight and find another way
                        cout << "Current HP: " << player_HP << endl;
                        cout << "No. of enemies: " << num_bandit << endl;
                        cout << "Continue to fight?" << endl;
                        cout << "1. Yes" << endl;
                        cout << "2. No" << endl;
                        do {
                            reply = validation();
                            if (reply != 1 && reply != 2)
                            {
                                cout << "Invalid input. Please try again." 
                                     << endl;
                            }
                        } while (reply != 1 && reply != 2);

                        if (reply == 2)
                        {
                            break; //leave this space
                        }
                    }
                }
            }

            if (num_bandit == 0)
            {
                player->setWin(true);

                cout << "All enemies leave the Entrance. You can leave now." 
                     << endl;
            }

            --move;
            player->setAction(move);
        }
        else
        {
            cout << "Time is not enough for today." << endl;
        }
    }
}
