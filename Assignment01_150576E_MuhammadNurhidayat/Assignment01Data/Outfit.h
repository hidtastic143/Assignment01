/*********************************************************************************************/
/*!
\file	Outfit.h
\author Muhammad Nurhidayat Bin Suderman
\par	150576E@mymail.nyp.edu.sg
\brief
Outfit is an inheritance to Item, adds SPECIAL to Dweller
*/
/*********************************************************************************************/
#ifndef OUTFIT_H
#define OUTFIT_H

#include "Item.h"
/*********************************************************************************************/
/*!	
Class Outfit:
\brief Outfit is an inheritance to Item. Outfit is initialised by using Item's constructor. Outfit adds to Dweller's SPECIAL when assigned and has more than 0 durability
*/
/*********************************************************************************************/
class Outfit : public Item
{
private:
	const int kSPECIAL;

public:
	Outfit(const std::string&, const int&, const int&);
	virtual ~Outfit();

	virtual void receiveDamage(const int &);
	const int getSPECIAL();
};

#endif