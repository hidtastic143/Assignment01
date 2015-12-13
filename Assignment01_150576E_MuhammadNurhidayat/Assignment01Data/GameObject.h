#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

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