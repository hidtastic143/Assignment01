#include "Outfit.h"

/*********************************************************************************************/
/*!
\brief
This constructor initialises the name, durability and SPECIAL of outfit
\param

\exception

\return

*/
/*********************************************************************************************/
Outfit::Outfit(const std::string& name, const int& durability, const int& SPECIAL)
:Item(name, durability), kSPECIAL(SPECIAL)
{
	
}

/*********************************************************************************************/
/*!
\brief
Outfit Destructor
\param

\exception

\return

*/
Outfit::~Outfit()
{

}

/*********************************************************************************************/
/*!
\brief
Calculates durability_ when Dweller sustains damage
\param

\exception

\return

*/
/*********************************************************************************************/
void Outfit::receiveDamage(const int& dmg)
{
	durability_ -= dmg;
}

/*********************************************************************************************/
/*!
\brief
Returns kSPECIAL of Dweller
\param

\exception

\return
kSPECIAL
*/
/*********************************************************************************************/	
const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}