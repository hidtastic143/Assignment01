#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

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