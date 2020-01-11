/*****************************************************************************
 * Header name: Garden
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: The header file of Garden.cpp. There is a bridge at 15m below
 *              the edge of the garden. It is a special route to win the game.
 *              Refer to Garden.cpp for details.
*****************************************************************************/
#ifndef GARDEN_HPP
#define GARDEN_HPP

#include "Space.hpp"

class Garden : public Space
{
public:
    Garden();
    void event(Fighter* player);
};

#endif
