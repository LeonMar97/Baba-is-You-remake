#pragma once
#include "CollisionStrategy.h"

class CollisionStrategyDefault : public CollisionStrategy {
public:
	CollisionStrategyDefault();
	BaseObject* handleCollision(BaseObject*, BaseObject*)
};