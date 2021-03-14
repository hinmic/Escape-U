/*****************************************************************************
 * Header name: Entrance
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: The headere file of Entrance.cpp. Bandits mainly stay at the
 *              Entrance to block the exit route of the player. Refer to
 *              Entrance.cpp for details.
*****************************************************************************/
#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP

#include "Space.hpp"

class Entrance : public Space
{
private:
    int num_bandit; //the number of Bandits at this space

public:
    Entrance(); //default constructor
    void event(Fighter* player); //fight the Bandits
    void setNum(int num); //setter of num_bandit
};

#endif
