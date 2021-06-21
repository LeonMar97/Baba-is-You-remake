#pragma once
#include "CollisionStrategy.h"
#include "OperationsHead/OperationMove.h"

class CollisionStrategyPush: public CollisionStrategy {
public:
	CollisionStrategyDefault();
	BaseObject* handleCollision(BaseObject*, BaseObject*)
};
