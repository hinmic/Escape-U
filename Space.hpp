/*****************************************************************************
 * Header name: Space
 * Author:      Chi Hin Ng
 * Date:        10-12-2019
 * Description: The header file of Space.cpp. Space class represents the space
 *              the player can be in. It is an abstract class. Refer to
 *              Space.cpp for details.
*****************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>

#include "Fighter.hpp"
#include "Bandit.hpp"
#include "validation.hpp"

using std::cout;
using std::endl;
using std::string;

class Space
{
protected:
    Space* top;
    Space* right;
    Space* left;
    Space* bottom;
    string label; //indicate what type of object it is

public:
    Space(); //default constructor
    Space(string name); //constructor
    virtual ~Space(); //virtual destructor
    string getLabel(); //getter of label
    void setT(Space* zone); //setter of top
    Space* getTop(); //getter of top pointer
    void setR(Space* zone); //setter of right
    Space* getRight(); //getter of right pointer
    void setL(Space* zone); //setter of left
    Space* getLeft(); //getter of left pointer
    void setB(Space* zone); //setter of bottom
    Space* getBottom(); //getter of bottom pointer
    Space* changeZone(); //change the Space
    virtual void event(Fighter* player) = 0; //unique in different spaces
};

#endif
