#include "Weapon.h"

Weapon::Weapon(const std::string& name, const int& durability, const int& attackDmg)
:Item(name, durability), kAttackDmg(attackDmg)
{
}


Weapon::~Weapon()
{
}

void Weapon::receiveDamage(const int& dmg)
{
	durability_ -= (dmg / 2);
}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}