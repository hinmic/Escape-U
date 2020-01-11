/*****************************************************************************
 * Header name: ActivityRm
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: The header file of ActivityRm.cpp. ActivityRm is a Space for
 *              the player to end a turn and get some tools.
*****************************************************************************/
#ifndef ACTIVITYRM_HPP
#define ACTIVITYRM_HPP

#include "Space.hpp"

class ActivityRm : public Space
{
private:
    int turn;

public:
    ActivityRm(); //default constructor
    void setTurn(int round); //setter of turn
    int getTurn(); //getter of turn
    void event(Fighter* player); //the action the player can take here
};

#endif
