/*****************************************************************************
 * Header name: Fighter
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: The header file of Fighter.cpp. Fighter is a class that
 *              represents the main character of the game (i.e. the player).
 *              Refer to Fighter.cpp for details.
*****************************************************************************/
#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include "Bandit.hpp"

#include <list>
#include <string>

using std::string;

class Fighter : public Bandit
{
private:
    std::list<std::string> container; //items the character can carry
    int capacity; //capacity of the container
    int action; //no. of actions that players can take in a turn
    bool escape; //escape mode
    bool win_status; //true -> win the game

public:
    Fighter(); //default constructor
    ~Fighter(); //destructor
    void setWin(bool sWin); //setter of win_status
    bool getWin(); //getter of win_status
    void setCap(int size); //setter of capacity
    int getCap(); //getter of capacity
    void setAction(int move); //setter of action
    int getAction(); //getter of action
    bool getEsp(); //getter of escape
    void checkItem(); //check the container and update the player's ability
    string getFront(); //getter of the 1st item
    string getBack(); //getter of the 2nd item
    void addFront(int item); //add an item at the front of the container
    void addBack(int item); //add an item at the end of the container
    void popFront(); //remove an item at the front of the container
    void popBack(); //remove an item at the front of the container
};

#endif
