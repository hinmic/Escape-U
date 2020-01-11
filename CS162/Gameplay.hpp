/*****************************************************************************
 * Header name: Gameplay
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: This is the header file of Gameplay.cpp. Gameplay holds the
 *              structure of the game and display the progress to the player.
 *              Refer to Gameplay.cpp for details.
*****************************************************************************/
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Bandit.hpp"
#include "Fighter.hpp"
#include "Space.hpp"
#include "Street.hpp"
#include "ActivityRm.hpp"
#include "FAstation.hpp"
#include "Entrance.hpp"
#include "Garden.hpp"

class Gameplay
{
private:
    Fighter* player; //the main character
    int day; //no. of turns in the game
    Space* location;
    ActivityRm* mainRm;
    Space* space1;
    Space* space2;
    Space* space3;
    Space* space4;
    Space* space5;
    Space* space6;
    Space* space7;

public:
    Gameplay(); //default constructor
    void spaceLink(); //fucntion that link different spaces as the game map
    void menu();
    ~Gameplay(); //destructor
};

#endif
