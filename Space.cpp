/*****************************************************************************
 * Class name:  Space
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: Space class has 4 Space pointers which each of them links to
 *              another space object. It is the base class of all other
 *              objects that can be found in the game.
*****************************************************************************/
#include "Space.hpp"

/*****************************************************************************
 * Description: The default constructor. Set pointers to NULL by default.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Space::Space()
{
    top = NULL;
    bottom = NULL;
    left = NULL;
    right = NULL;
    label = "";
}

/*****************************************************************************
 * Description: Constructor that takes pointers of Space object to set member
 *              variables.
 * Arguments:   the label of the type of space
 * Returns:     None
*****************************************************************************/
Space::Space(string name)
{
    top = NULL;
    right = NULL;
    left = NULL;
    bottom = NULL;
    label = name;
}

/*****************************************************************************
 * Description: A virtual destructor.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Space::~Space()
{
    //virtual
}

/*****************************************************************************
 * Description: Getter function of label.
 * Arguments:   None
 * Returns:     label of the object
*****************************************************************************/
string Space::getLabel()
{
    return label;
}

/*****************************************************************************
 * Description: Setter function of top.
 * Arguments:   A pointer to a Space object
 * Returns:     None
*****************************************************************************/
void Space::setT(Space* zone)
{
    top = zone;
}

/*****************************************************************************
 * Description: Getter function of top.
 * Argumeents:  None
 * Returns:     a pointer to a Space object
*****************************************************************************/
Space* Space::getTop()
{
    return top;
}

/*****************************************************************************
 * Description: Setter function of bottom.
 * Arguments:   A pointer to a Space object
 * Returns:     None
*****************************************************************************/
void Space::setB(Space* zone)
{
    bottom = zone;
}

/*****************************************************************************
 * Description: Getter function of bottom.
 * Arguments:   A pointer to a Space object
 * Returns:     None
*****************************************************************************/
Space* Space::getBottom()
{
    return bottom;
}

/*****************************************************************************
 * Description: Setter function of right.
 * Arguments:   A pointer to a Space object
 * Returns:     None
*****************************************************************************/
void Space::setR(Space* zone)
{
    right = zone;
}

/*****************************************************************************
 * Description: Getter function of right.
 * Arguments:   None
 * Returns:     a pointer to a Space object
*****************************************************************************/
Space* Space::getRight()
{
    return right;
}

/*****************************************************************************
 * Description: Setter function of left.
 * Arguments:   A pointer to a Space object
 * Returns:     None
*****************************************************************************/
void Space::setL(Space* zone)
{
    left = zone;
}

/*****************************************************************************
 * Description: Getter function of left.
 * Arguments:   None
 * Returns:     a pointer to a Space object
*****************************************************************************/
Space* Space::getLeft()
{
    return left;
}

/*****************************************************************************
 * Description: Function to move to another zone.
 * Arguments:   a pointer to a Space object
 * Returns:     a pointer to a Space object
*****************************************************************************/
Space* Space::changeZone()
{
    bool valid = false;
    string place1;
    string place2;
    string place3;
    string place4;

    Space* destination1 = top;
    if (destination1 != NULL)
    {
        place1 = destination1->getLabel(); //get the name of destination
    }
    else
    {
        place1 = "N/A";
    }

    Space* destination2 = left;
    if (destination2 != NULL)
    {
        place2 = destination2->getLabel(); //get the name of destination
    }
    else
    {
        place2 = "N/A";
    }

    Space* destination3 = right;
    if (destination3 != NULL)
    {
        place3 = destination3->getLabel(); //get the name of destination
    }
    else
    {
        place3 = "N/A";
    }

    Space* destination4 = bottom;
    if (destination4 != NULL)
    {
        place4 = destination4->getLabel(); //get the name of destination
    }
    else
    {
        place4 = "N/A";
    }

    int reply = 0;

    while (!valid)
    {
        cout << "Where do you want to go?" << endl;
        cout << "1. " << place1 << endl;
        cout << "2. " << place2 << endl;
        cout << "3. " << place3 << endl;
        cout << "4. " << place4 << endl;

        do {
            reply = validation();
            if (reply < 1 || reply > 4)
            {
                cout << "Invalid input. Please try again." << endl;
            }
        } while (reply < 1 || reply > 4);

        if (reply == 1)
        {
            if (destination1 != NULL)
            {
                valid = true;
                return destination1;
            }
            else
            {
                cout << "The destination does not exist." << endl;
            }
        }
        else if (reply == 2)
        {
            if (destination2 != NULL)
            {
                valid = true;
                return destination2;
            }
            else
            {
                cout << "The destination does not exist." << endl;
            }
        }
        else if (reply == 3)
        {
            if (destination3 != NULL)
            {
                valid = true;
                return destination3;
            }
            else
            {
                cout << "The desination does not exist." << endl;
            }
        }
        else
        {
            if (destination4 != NULL)
            {
                valid = true;
                return destination4;
            }
            else
            {
                cout << "The destination does not exist." << endl;
            }
        }
    }
}

/*****************************************************************************
 * Description: The function that allows the player to take special moves in
 *              particular space. Define in derived class.
 * Arguments:   a pointer to the character of the player
 * Returns:     None
*****************************************************************************/
void Space::event(Fighter* player)
{
    //virtual
}

