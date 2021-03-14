/*****************************************************************************
 * Class name:  Fighter
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: Fighter represents the player in the game. He is weak compared
 *              to Bandits. However, a Fighter can collect at most 3 different
 *              items. It inherits from class Bandit.
*****************************************************************************/
#include "Fighter.hpp"

/*****************************************************************************
 * Description: Default constructor set the ability of a Fighter.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Fighter::Fighter() : Bandit(100, 100, 10, 10)
{
    capacity = 2;
    action = 1;
    escape = false;
    win_status = false;
    addFront(2);
    addFront(3);
}

/*****************************************************************************
 * Description: Check the items in the container and update the player's
 *              status.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
void Fighter::checkItem()
{
    string item1;
    string item2;

    if (!container.empty())
    {
        item1 = container.front();
        item2 = container.back();

        if (item1 == "rope")
        {
            escape = true;
        }
        else if (item2 == "rope")
        {
            escape = true;
        }
        else
        {
            escape = false;
        }

        if (item1 != "gas_mask" && item2 != "gas_mask")
        {
            HP -= 20;
        }

        if (item1 == "umbrella")
        {
            armor = 10;
        }
        else if (item2 == "umbrella")
        {
            armor = 10;
        }
        else
        {
            armor = 0;
        }

        if (item1 == "brick")
        {
            attack = 60;
        }
        else if (item2 == "brick")
        {
            attack = 60;
        }
        else
        {
            attack = 10;
        }
    }
}

/*****************************************************************************
 * Description: Destructor. Clear the container after a game.
 * Argments:    None
 * Returns:     None
*****************************************************************************/
Fighter::~Fighter()
{
    while (!container.empty())
    {
        container.pop_front();
    }
}

/*****************************************************************************
 * Description: Setter of win_status
 * Arguments:   true/false
 * Returns:     None
*****************************************************************************/
void Fighter::setWin(bool sWin)
{
    win_status = sWin;
}

/*****************************************************************************
 * Description: Getter of win_status
 * Arguments:   None
 * Returns:     win_status
*****************************************************************************/
bool Fighter::getWin()
{
    return win_status;
}

/*****************************************************************************
 * Description: Setter of action.
 * Arguments:   no. of actions
 * Returns:     None
*****************************************************************************/
void Fighter::setAction(int move)
{
    action = move;
}

/*****************************************************************************
 * Description: Getter of action.
 * Arguments:   None
 * Returns:     no. of actions
*****************************************************************************/
int Fighter::getAction()
{
    return action;
}

/*****************************************************************************
 * Description: Setter of capacity.
 * Arguments:   the capacity of the container
 * Retuns:      None
*****************************************************************************/
void Fighter::setCap(int size)
{
    capacity = size;
}

/*****************************************************************************
 * Description: Getter of capacity.
 * Arguments:   None
 * Returns:     capacity of items container
*****************************************************************************/
int Fighter::getCap()
{
    return capacity;
}

/*****************************************************************************
 * Description: Getter of escape.
 * Arguments:   None
 * Returns:     escape status
*****************************************************************************/
bool Fighter::getEsp()
{
    return escape;
}

/*****************************************************************************
 * Description: Getter of 1st item.
 * Arguments:   None
 * Reeturns:    name of 1st item
*****************************************************************************/
string Fighter::getFront()
{
    return container.front();
}

/*****************************************************************************
 * Description: Getter of 2nd item.
 * Arguments:   None
 * Returns:     name of 2nd item
*****************************************************************************/
string Fighter::getBack()
{
    return container.back();
}

/*****************************************************************************
 * Description: Add an item at the front of the container.
 * Arguments:   a number indicating what kind of item shall be added
 * Returns:     None
*****************************************************************************/
void Fighter::addFront(int item)
{
    if (item == 1)
    {
        container.push_front("rope");
    }
    else if (item == 2)
    {
        container.push_front("umbrella");
    }
    else if (item == 3)
    {
        container.push_front("gas_mask");
    }
    else if (item == 4)
    {
        container.push_front("brick");
    }

    --capacity;
}

/*****************************************************************************
 * Description: Add an item at the end of a container.
 * Arguments:   a number indicating what kind of item shall be added
 * Returns:     None
*****************************************************************************/
void Fighter::addBack(int item)
{
    if (item == 1)
    {
        container.push_back("rope");
    }
    else if (item == 2)
    {
        container.push_back("umbrella");
    }
    else if (item == 3)
    {
        container.push_back("gas_mask");
    }
    else if (item == 4)
    {
        container.push_back("brick");
    }

    --capacity;
}

/*****************************************************************************
 * Description: Remove an item at the front of the container.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
void Fighter::popFront()
{
    container.pop_front();

    ++capacity;
}

/*****************************************************************************
 * Descrption: Remove an item at the end of the container.
 * Arguments:  None
 * Returns:    None
*****************************************************************************/
void Fighter::popBack()
{
    container.pop_back();

    ++capacity;
}
