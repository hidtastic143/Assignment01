#include "Item.h"

Item::Item(const std::string& name, const int& durability)
:GameObject(name), durability_(durability)
{

}

Item::~Item()
{

}

const int Item::getDurability()
{
	return durability_;
}