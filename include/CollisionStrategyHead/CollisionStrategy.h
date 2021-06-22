#pragma once
#include "BaseObject.h"


//design pattern strategy
class CollisionStrategy {
public:	
	CollisionStrategy(int);
	virtual BaseObject* handleCollision(BaseObject*, BaseObject*) = 0;
	virtual bool operator<(CollisionStrategy&); //for comparing two strategies
	virtual bool move(BaseObject& curYou, const Direction& dir) { return false; }
private:
	const int m_priority; //priority of interactions with board for making interactions clear and consistent
};

//comparator for std::set for sorting attributes based on priorities
class ColStrCmp {
public:
	bool operator()(const std::shared_ptr<CollisionStrategy>& a,
					const std::shared_ptr<CollisionStrategy>& b) const{
	return *a < *b;
	}
};
