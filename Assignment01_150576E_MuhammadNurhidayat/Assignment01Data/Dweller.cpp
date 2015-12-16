#include "Dweller.h"
/*********************************************************************************************/
/*!
\brief	
This constructor initialises the private members the Dweller have

\param
const string& name, const int& special

\exception

\return

*/
/*********************************************************************************************/
Dweller::Dweller(const std::string& name, const int& special)
:GameObject(name), SPECIAL_(special), position_(0, 0), health_(100), radiation_(0), stimpak_(0), radaway_(0), outfit_(0), weapon_(0)
{

}

/*********************************************************************************************/
/*!
\brief
Dweller Destructor

\param

\exception

\return

*/
/*********************************************************************************************/
Dweller::~Dweller()
{

}

/*********************************************************************************************/
/*!
\brief
Returns SPECIAL_ or newSpecial depending if Outfit is assigned to Dweller
\param

\exception

\return
SPECIAL_ or newSpecial
*/
/*********************************************************************************************/
const int Dweller::getSPECIAL()
{
	if (outfit_ == 0 || outfit_->getDurability() < 1)
		return SPECIAL_;
	else
	{
		int newSPECIAL = 0;
		int outfitSPECIAL1, outfitSPECIAL2, dwellerSPECIAL1, dwellerSPECIAL2;

		for (int digit = 1000000; digit > 0; digit /= 10)
		{
				outfitSPECIAL1 = outfit_->getSPECIAL() / digit;
				outfitSPECIAL2 = outfit_->getSPECIAL() / (digit * 10);
				outfitSPECIAL2 *= 10;

				outfitSPECIAL1 -= outfitSPECIAL2;

				dwellerSPECIAL1 = SPECIAL_ / digit;
				dwellerSPECIAL2 = SPECIAL_ / (digit * 10);
				dwellerSPECIAL2 *= 10;

				dwellerSPECIAL1 -= dwellerSPECIAL2;

			if ((outfitSPECIAL1 + dwellerSPECIAL1) < 9)
			{
				newSPECIAL += ((outfitSPECIAL1 + dwellerSPECIAL1) * digit);
			}
			else
			{
				newSPECIAL += (9 * digit);
			}
		}
		return newSPECIAL;
	}
}

/*********************************************************************************************/
/*!
\brief
Returns current health of Dweller
\param

\exception

\return
health_
*/
/*********************************************************************************************/
const int Dweller::getCurrentHealth()
{
	return health_;
}

/*********************************************************************************************/
/*!
\brief
This function will return the amount of Radiation the Dweller has attained
\param

\exception

\return
radiation_
*/
/*********************************************************************************************/
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

/*********************************************************************************************/
/*!
\brief
Returns 1 or Weapon's damaged if assigned to Dweller
\param

\exception

\return
1 or weapon->getAttackDmg()
*/
/*********************************************************************************************/
const int Dweller::getAttackDmg()
{
	if (weapon_ != 0 && weapon_->getDurability() > 0)
		return weapon_->getAttackDmg();
	else
		return 1;

}

/*********************************************************************************************/
/*!
\brief
Sets position of Dweller
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::setPosition(const Vec2D& position)
{
	position_.x = position.x;
	position_.y = position.y;
}

/*********************************************************************************************/
/*!
\brief
Returns position of Dweller
\param

\exception

\return
position_
*/
/*********************************************************************************************/
const Vec2D Dweller::getPosition()
{
	return position_;
}

/*********************************************************************************************/
/*!
\brief
This function calculates the health_ of Dweller after sustaining damage
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::receiveHealthDamage(const int& dmg)
{
	health_ -= dmg;
}

/*********************************************************************************************/
/*!
\brief
This function calculates the health_ of Dweller after sustaining radiation damage
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::receiveRadDamage(const int& radDmg)
{
	health_ -= radDmg;
}

/*********************************************************************************************/
/*!
\brief
This function will point to receiveDamage() if there are Items assigned to Dweller and Dweller receive damage
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::receiveEquipmentDamage(const int& equipDmg)
{
	if (outfit_ != 0)
	outfit_->receiveDamage(equipDmg);
	if (weapon_ != 0)
	weapon_->receiveDamage(equipDmg);
}

/*********************************************************************************************/
/*!
\brief
Calculates the number of stimpak the Dweller has after adding Stimpak
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::addStimpak(const int& stimpak)
{
	stimpak_ += stimpak;
}

/*********************************************************************************************/
/*!
\brief
Calculates the number of radAway Dweller has after adding
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::addRadAway(const int& radaway)
{
	radaway_ += radaway;
}

/*********************************************************************************************/
/*!
\brief
Calculates the health after stimpak is used and takes away one stimpak
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::useStimpak()
{
	health_ += 20;

	if (health_ >= 100)
	{
		health_ = 100;
	}
	stimpak_--;
}

/*********************************************************************************************/
/*!
\brief
This function calculates the radiation and removes one radaway after radaway is used 
\param

\exception

\return

*/
/*********************************************************************************************/
void Dweller::useRadAway()
{
	if (radiation_ >= 1)
	{
		radiation_ -= 10;
	}
	radaway_--;
}

/*********************************************************************************************/
/*!
\brief
Assigns an Outfit to a Dweller
\param

\exception

\return
outfit_
*/
/*********************************************************************************************/
Outfit* Dweller::assignOutfit(Outfit* outfit) 
{
	if (outfit_ == 0)
	{
		outfit_ = new Outfit(outfit->getName(), outfit->getDurability(), outfit->getSPECIAL());
	}
	else
	{
		delete outfit_;
		outfit_ = new Outfit(outfit->getName(), outfit->getDurability(), outfit->getSPECIAL());
	}
	return outfit_;
}

/*********************************************************************************************/
/*!
\brief
Assigns Weapon to Dweller
\param

\exception

\return
weapon_
*/
/*********************************************************************************************/
Weapon* Dweller::assignWeapon(Weapon* weapon)
{
	if (weapon_ == 0)
	{
		weapon_ = new Weapon(weapon->getName(), weapon->getDurability(), weapon->getAttackDmg());
	}
	else
	{
		delete weapon_;
		weapon_ = new Weapon(weapon->getName(), weapon->getDurability(), weapon->getAttackDmg());
	}
	return weapon_;
}

/*
*	this function checks if Dweller is Alive or Dead
*/
bool Dweller::isDead()
{
	if (health_ <= 0)
		return 1;

	else
		return 0;
}