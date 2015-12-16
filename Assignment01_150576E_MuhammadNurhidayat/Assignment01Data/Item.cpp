#include "Item.h"

/*********************************************************************************************/
/*!
\brief
Initialises Outfit and Weapon with this constructor, name and durability
\param

\exception

\return

*/
/*********************************************************************************************/
Item::Item(const std::string& name, const int& durability)
:GameObject(name), durability_(durability)
{

}

/*********************************************************************************************/
/*!
\brief
Destructor for Item
\param

\exception

\return

*/
/*********************************************************************************************/
Item::~Item()
{

}

/*********************************************************************************************/
/*!
\brief
Returns durability of Item
\param

\exception

\return
durability_
*/
/*********************************************************************************************/
const int Item::getDurability()
{
	return durability_;
}