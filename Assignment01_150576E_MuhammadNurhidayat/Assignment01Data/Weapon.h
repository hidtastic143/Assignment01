/*********************************************************************************************/
/*!
\file	Weapon.h
\author Muhammad Nurhidayat Bin Suderman
\par	150576E@mymail.nyp.edu.sg
\brief
Weapon increases the damage of Dweller
*/
/*********************************************************************************************/
#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
/*********************************************************************************************/
/*!
Class Item:
\brief Weapon is an inheritance to Item. Weapon increases the damage Dwellers deal
*/
/*********************************************************************************************/
class Weapon : public Item
{
private:
	const int kAttackDmg;

public:
	Weapon(const std::string&, const int&, const int&);
	virtual ~Weapon();

	virtual void receiveDamage(const int&);
	const int getAttackDmg();
};

#endif