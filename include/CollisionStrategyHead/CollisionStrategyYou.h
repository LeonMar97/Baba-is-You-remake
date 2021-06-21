#pragma once
#include "CollisionStrategy.h"
#include "OperationsHead/OperationMove.h"

class CollisionStrategyYou : public CollisionStrategy {
public:
	CollisionStrategyYou();
	BaseObject* handleCollision(BaseObject*, BaseObject*);
	bool move(BaseObject& curYou, const Direction& dir) override;
};
