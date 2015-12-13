#ifndef OUTFIT_H
#define OUTFIT_H

#include "Item.h"

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