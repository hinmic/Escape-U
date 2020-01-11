/*****************************************************************************
 * Class name:  Gameplay
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: This class has functions that build the game structure,
 *              interact with the player to run the game and display the game
 *              progress.
*****************************************************************************/
#include "Gameplay.hpp"

/*****************************************************************************
 * Description: Build the linked structure of Spaces.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
void Gameplay::spaceLink()
{
    //Create different Spaces
    Entrance* ent1 = new Entrance;
    space1 = ent1;

    Entrance* ent2 = new Entrance;
    space7 = ent2;

    Street* street1 = new Street;
    space2 = street1;

    Street* street2 = new Street;
    space6 = street2;

    FAstation* FAS = new FAstation;
    space4 = FAS;

    ActivityRm* actRM = new ActivityRm;
    space3 = actRM;

    Garden* garden = new Garden;
    space5 = garden;

    //link the spaces
    space1->setR(space2);
    space7->setL(space6);
    space2->setL(space1);
    space2->setR(space3);
    space6->setR(space7);
    space6->setL(space3);
    space6->setT(space5);
    space5->setB(space6);
    space5->setL(space4);
    space4->setR(space5);
    space4->setB(space3);
    space3->setT(space4);
    space3->setL(space2);
    space3->setR(space6);

    location = space3;
    mainRm = actRM;
}

/*****************************************************************************
 * Description: Default constructor that setup the game structure.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Gameplay::Gameplay()
{
    day = 0;
    player = new Fighter();

    spaceLink();
}

/*****************************************************************************
 * Description: Menu that interacts with the player and runs the game.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
void Gameplay::menu()
{
    cout << "A group of Bandits suddenly come to the University and block all"
         << " the entrances." << endl;
    cout << "They cut all kinds of connections between the University and the"
         << " outside world." << endl;
    cout << "You have 15 days to find methods to leave the University and "
         << " seek help from outside." << endl;
    cout << "If you can do so within 15 days, the University will run out of "
         << "food supply and all the people inside will die." << endl;
    cout << endl << "So far, the only method to leave the University is to "
         << "defeat all the bandits and leave from the entrance." << endl;
    cout << "You try to walk close to the entrance and the bandits fire "
         << "toxic tear gas into the University." << endl;
    cout << "Everyone without a gas mask will lose HP every turn." << endl;
    cout << "The game starts." << endl;

    int playerHP = player->getHP();
    bool win = player->getWin();
    string place;

    while (day < 15)
    {
        location = location->changeZone();

        //Display the game progress
        place = location->getLabel();
        cout << "Day: " << day << endl;
        cout << "You are now at " << place << endl;

        location->event(player); //take an action
        player->checkItem(); //update the player's status        
        day = mainRm->getTurn(); //update the day
        playerHP = player->getHP(); //check fighter's HP
        cout << "Current HP: " << playerHP << endl;
        win = player->getWin(); //check the winning status

        if (win)
        {
             cout << "You successfully leave the University. You win." 
             << endl;
             break;
        }
        else if (playerHP < 1)
        {
             cout << "You die. Game over!" << endl;
             break;
        }
    }

    if (day >= 15)
    {
        cout << "You failed to escape the University within 15 days. Game "
             << "over." << endl;
    }
}

/*****************************************************************************
 * Description: Destructor. Free memories.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Gameplay::~Gameplay()
{
    delete space1;
    delete space2;
    delete space3;
    delete space4;
    delete space5;
    delete space6;
    delete space7;

    delete player;
}
