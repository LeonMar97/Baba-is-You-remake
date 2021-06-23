#pragma once
#include "BaseObject.h"


//design pattern strategy
class Property {
public:	
	Property(int);
	virtual BaseObject* handleCollision(BaseObject*, BaseObject*) = 0;
	virtual bool operator<(Property&); //for comparing two strategies
	virtual bool move(BaseObject& curYou, const Direction& dir) { return false; }
private:
	const int m_priority; //priority of interactions with board for making interactions clear and consistent
};

//comparator for std::set for sorting attributes based on priorities
class ColStrCmp {
public:
	bool operator()(const std::shared_ptr<Property>& a,
					const std::shared_ptr<Property>& b) const{
	return *a < *b;
	}
};
