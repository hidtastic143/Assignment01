/*********************************************************************************************/
/*!
\file	Dweller.h
\author Muhammad Nurhidayat Bin Suderman
\par	150576E@mymail.nyp.edu.sg
\brief
Dweller header file is the main object to the game that can be assigned with items
*/
/*********************************************************************************************/
#ifndef DWELLERS_H
#define DWELLERS_H

#include "GameObject.h"
#include "Outfit.h"
#include "Weapon.h"
#include "Vec2D.h"
/*********************************************************************************************/
/*!
Class Dweller:
\brief Dweller, an inheritance to GameObject. It will initialise all it's private members with its constructor
*/
/*********************************************************************************************/
class Dweller : public GameObject
{
private:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;

public:
	Dweller(const std::string&, const int&);
	virtual ~Dweller();

	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();
	void setPosition(const Vec2D&);
	const Vec2D getPosition();
	void receiveHealthDamage(const int&);
	void receiveRadDamage(const int&);
	void receiveEquipmentDamage(const int&);
	void addStimpak(const int&);
	void addRadAway(const int&);
	void useStimpak();
	void useRadAway();
	Outfit* assignOutfit(Outfit*);
	Weapon* assignWeapon(Weapon*);
	bool isDead();
};
#endif