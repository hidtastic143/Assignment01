#include "GameObject.h"

int GameObject::count_ = 0;


/*********************************************************************************************/
/*!
\brief
Initialises GameObject with name and adds count_
\param

\exception

\return

*/
/*********************************************************************************************/
GameObject::GameObject(const std::string& name)
:kName(name)
{
	count_++;
}

/*********************************************************************************************/
/*!
\brief
Count is decremented when delete is called
\param

\exception

\return

*/
/*********************************************************************************************/
GameObject::~GameObject()
{
	count_--;
}

/*********************************************************************************************/
/*!
\brief
Returns name of GameObject
\param

\exception

\return
kName
*/
/*********************************************************************************************/
std::string GameObject::getName()
{
	return kName;
}

/*********************************************************************************************/
/*!
\brief
Returns count_
\param

\exception

\return
count_
*/
/*********************************************************************************************/
int GameObject::getCount()
{
	return count_;
}