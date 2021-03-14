/*****************************************************************************
 * Header name: Bandit
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: The header file of Bandit.cpp. Bandit is the enemy (NPC) of
 *              the player. A bandit overpowers the fighter as he has advanced
 *              gears. Refer to Bandit.cpp for details.
*****************************************************************************/
#ifndef BANDIT_HPP
#define BANDIT_HPP

class Bandit
{
protected:
    int maxHP;
    int HP;
    int armor;
    int attack;

public:
    Bandit(); //default constructor
    Bandit(int sMax, int sHP, int sArmor, int sAtk); //constructor
    virtual ~Bandit(); //destructor
    int getAtk(); //getter function of attack
    int getHP(); //getter function of HP
    void setHP(int sHP); //setter function of HP
    void takeDamage(int damage); //update HP after receiving an attack
};

#endif
