#pragma once
#include "CollisionStrategy.h"
#include "OperationsHead/OperationRemove.h"

class CollisionStrategySink: public CollisionStrategy {
public:
	CollisionStrategySink(Board& board);
	BaseObject* handleCollision(BaseObject*, BaseObject*);
private:
	Board& m_board;
};
