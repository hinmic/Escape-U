/*****************************************************************************
 * Header name: Street
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: The header file of Street.cpp. Street class inherits from
 *              Space class. It connects the Entrance and the Activity Room.
 *              Refer to Street.cpp for details.
*****************************************************************************/
#ifndef STREET_HPP
#define STREET_HPP

#include "Space.hpp"
#include "Fighter.hpp"

class Street : public Space
{
public:
    Street(); //default contructor
    void event(Fighter* player); //interact with players in this Space
};

#endif
