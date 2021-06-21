#pragma once
#include "BaseObject.h"


class CollisionStrategy {
public:	
	CollisionStrategy(int);
	virtual BaseObject* handleCollision(BaseObject*, BaseObject*) = 0;
	virtual bool operator<(CollisionStrategy&);
	virtual bool move(BaseObject& curYou, const Direction& dir) { return false; }
private:
	const int m_priority; //priority of interactions with board for making interactions clear and consistent
};

class ColStrCmp {
public:
	bool operator()(const std::shared_ptr<CollisionStrategy>& a, const std::shared_ptr<CollisionStrategy>& b) const{
	return *a < *b;
}
};
