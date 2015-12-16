#include "Weapon.h"

/*********************************************************************************************/
/*!
\brief
This constructor initialises name, durability and attackDmg of weapon
\param

\exception

\return

*/
/*********************************************************************************************/
Weapon::Weapon(const std::string& name, const int& durability, const int& attackDmg)
:Item(name, durability), kAttackDmg(attackDmg)
{
}

/*********************************************************************************************/
/*!
\brief
Weapon Destructor
\param

\exception

\return

*/
/*********************************************************************************************/
Weapon::~Weapon()
{
}

/*********************************************************************************************/
/*!
\brief
Reduces durability_ when Dweller is damaged
\param

\exception

\return

*/
/*********************************************************************************************/
void Weapon::receiveDamage(const int& dmg)
{
	durability_ -= (dmg / 2);
}

/*********************************************************************************************/
/*!
\brief
Returns damage value of weapon
\param

\exception

\return
kAttackDmg
*/
/*********************************************************************************************/
const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}