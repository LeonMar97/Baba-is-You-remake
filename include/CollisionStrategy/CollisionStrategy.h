#pragma once
#include "BaseObject.h"

class CollisionStrategy {
public:	
	CollisionStrategy(int);
	virtual BaseObject* handleCollision(BaseObject*, BaseObject*) = 0;
	virtual bool operator<(CollisionStrategy&);
private:
	const int m_priority; //priority of interactions with board for making interactions clear and consistent
};