/*****************************************************************************
 * Class name:  Bandit
 * Author:      Chi Hin Ng
 * Date:        10/12/2019
 * Description: Bandit is a type of NPC character that are very strong, 
 *              compared to the character control to the player. Bandits will
 *              only be found in some zones. The player loses if he/she cannot
 *              survive for several rounds when fighting with a Bandit.
*****************************************************************************/
#include "Bandit.hpp"

/*****************************************************************************
 * Description: The default constructor sets the ability of a bandit by
 *              default.
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Bandit::Bandit()
{
    maxHP = 100;
    HP = 100;
    armor = 30;
    attack = 30;
}

/*****************************************************************************
 * Description: Constructor takes data and sets the ability of a Bandit.
 * Arguments:   value of maxHP, HP, armor and attack
 * Returns:     None
*****************************************************************************/
Bandit::Bandit(int sMax, int sHP, int sArmor, int sAtk)
{
    maxHP = sMax;
    HP = sHP;
    armor = sArmor;
    attack = sAtk;
}

/*****************************************************************************
 * Description: Virtual destructor. 
 * Arguments:   None
 * Returns:     None
*****************************************************************************/
Bandit::~Bandit()
{
    //virtual
}

/*****************************************************************************
 * Description: Getter function of attack.
 * Arguments:   None
 * Returns:     the attack value
*****************************************************************************/
int Bandit::getAtk()
{
    return attack;
}

/*****************************************************************************
 * Description: Getter function of HP.
 * Arguments:   None
 * Returns:     HP value
*****************************************************************************/
int Bandit::getHP()
{
    return HP;
}

/*****************************************************************************
 * Description: Setter function of HP.
 * Arguments:   HP value
 * Returns:     None
*****************************************************************************/
void Bandit::setHP(int sHP)
{
    HP = sHP;
}

/*****************************************************************************
 * Description: Calculate the damage taken and edit the HP.
 * Arguments:   damage from another character
 * Returns:     None
*****************************************************************************/
void Bandit::takeDamage(int damage)
{
    damage -= armor;
    if (damage > 0)
    {
        HP -= damage;
    }
}
