#pragma once
#include "BaseObject.h"


//design pattern strategy
//reason for this is to distinguish between actual attribute block with the attribute mechanism interaction
//once a noun-conjunction-attribute is detected, the relevant property of attribute is equipped
//to noun and thus gives all instances of it this property
class Property {
public:	
	Property(int);
	virtual BaseObject* handleCollision(BaseObject*, BaseObject*) = 0;
	virtual bool move(BaseObject& curYou, const Direction& dir) { return false; }

	//the properties of each object are present in a sorted set, and property with the highest
	//priority is the one that is most relevant
	virtual bool operator<(Property&); //for comparing two strategies
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
