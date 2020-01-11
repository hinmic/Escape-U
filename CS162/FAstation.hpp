/*****************************************************************************
 * Header file: FAstation
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: The header file of FAstation.cpp. A player recovers in this
 *              Space. Refer to FAstation.cpp for details.
*****************************************************************************/
#ifndef FASTATION_HPP
#define FASTATION_HPP

#include "Space.hpp"

class FAstation : public Space
{
public:
    FAstation(); //default constructor
    void event(Fighter* player); //interact with players in this Space
};

#endif
