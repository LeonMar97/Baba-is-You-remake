#pragma once
#include "CollisionStrategy.h"
#include "OperationsHead/OperationMove.h"

class CollisionStrategyPush: public CollisionStrategy {
public:
	CollisionStrategyPush();
	BaseObject* handleCollision(BaseObject*, BaseObject*);
};
