#pragma once
#include "CollisionStrategy.h"

class CollisionStrategyStop: public CollisionStrategy {
public:
	CollisionStrategyStop();
	BaseObject* handleCollision(BaseObject*, BaseObject*);
};
