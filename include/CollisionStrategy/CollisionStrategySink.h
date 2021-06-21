#pragma once
#include "CollisionStrategy.h"
#include "OperationsHead/OperationRemove.h"

class CollisionStrategySink: public CollisionStrategy {
public:
	CollisionStrategySink();
	BaseObject* handleCollision(BaseObject*, BaseObject*)
};
