#include "Dweller.h"

Dweller::Dweller(const std::string& name, const int& special)
:GameObject(name), SPECIAL_(special), position_(0, 0), health_(100), radiation_(0), stimpak_(0), radaway_(0), outfit_(0), weapon_(0)
{

}

Dweller::~Dweller()
{

}

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

const int Dweller::getCurrentHealth()
{
	return health_;
}

const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

const int Dweller::getAttackDmg()
{
	if (weapon_ != 0 && weapon_->getDurability() > 0)
		return weapon_->getAttackDmg();
	else
		return 1;

}

void Dweller::setPosition(const Vec2D& position)
{
	position_.x = position.x;
	position_.y = position.y;
}

const Vec2D Dweller::getPosition()
{
	return position_;
}

void Dweller::receiveHealthDamage(const int& dmg)
{
	health_ -= dmg;
}

void Dweller::receiveRadDamage(const int& radDmg)
{
	health_ -= radDmg;
}

void Dweller::receiveEquipmentDamage(const int& equipDmg)
{
	if (outfit_ != 0)
	outfit_->receiveDamage(equipDmg);
	if (weapon_ != 0)
	weapon_->receiveDamage(equipDmg);
}

void Dweller::addStimpak(const int& stimpak)
{
	stimpak_ += stimpak;
}

void Dweller::addRadAway(const int& radaway)
{
	radaway_ += radaway;
}
void Dweller::useStimpak()
{
	health_ += 20;

	if (health_ >= 100)
	{
		health_ = 100;
	}
	stimpak_--;
}
void Dweller::useRadAway()
{
	if (radiation_ >= 1)
	{
		radiation_ -= 10;
	}
	radaway_--;
}

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


bool Dweller::isDead()
{
	if (health_ <= 0)
		return 1;

	else
		return 0;
}