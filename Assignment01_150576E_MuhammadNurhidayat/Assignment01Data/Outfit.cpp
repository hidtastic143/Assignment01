#include "Outfit.h"

Outfit::Outfit(const std::string& name, const int& durability, const int& SPECIAL)
:Item(name, durability), kSPECIAL(SPECIAL)
{
	
}

Outfit::~Outfit()
{

}

void Outfit::receiveDamage(const int& dmg)
{
	durability_ -= dmg;
}

const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}