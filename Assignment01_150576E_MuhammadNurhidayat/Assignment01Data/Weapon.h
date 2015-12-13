#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

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