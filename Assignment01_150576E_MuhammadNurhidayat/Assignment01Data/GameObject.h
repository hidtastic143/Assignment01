/*********************************************************************************************/
/*!
\file	GameObject.h
\author Muhammad Nurhidayat Bin Suderman
\par	150576E@mymail.nyp.edu.sg
\brief
GameObject class here to initialise name for its inheritance
*/
/*********************************************************************************************/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
/*********************************************************************************************/
/*!
Class GameObject:
\brief This GameObject is the base class or parent of classes Dweller and Item. GameObject is also used to initialised Names of Dweller and Item. GameObject is also used to count_ the number of objects initialised
*/
/*********************************************************************************************/
class GameObject
{
private:
	const std::string kName;
	static int count_;

protected:
	GameObject(const std::string&);

public:
	virtual ~GameObject();

	std::string getName();
	static int getCount();
};

#endif