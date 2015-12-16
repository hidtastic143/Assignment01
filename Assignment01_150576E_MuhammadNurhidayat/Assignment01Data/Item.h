/*********************************************************************************************/
/*!
\file	Item.h
\author Muhammad Nurhidayat Bin Suderman
\par	150576E@mymail.nyp.edu.sg
\brief
Item initialises name and durability for Weapon and Outfit
*/
/*********************************************************************************************/
#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"
/*********************************************************************************************/
/*!
Class Item:
\brief Item is an inheritance to GameObject. Item Class is used to initialise durability to the child (Outfit and Weapon). It has a virtual void function that doesnt carry out a function but its there so its inheritance can override it
*/
/*********************************************************************************************/
class Item : public GameObject
{
protected:
	int durability_;

public:
	Item(const std::string&, const int&);
	virtual ~Item();

	virtual void receiveDamage(const int&) = 0;
	const int getDurability();
};
#endif