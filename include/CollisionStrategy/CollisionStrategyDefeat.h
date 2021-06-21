
#pragma once
#include "CollisionStrategy.h"

class CollisionStrategyDefeat: public CollisionStrategy {
public:
	CollisionStrategyDefeat();
	BaseObject* handleCollision(BaseObject*, BaseObject*) override ;
};
