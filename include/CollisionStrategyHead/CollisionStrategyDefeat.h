#pragma once
#include "CollisionStrategy.h"
#include "OperationRemove.h"
#include "CollisionStrategyYou.h"

class CollisionStrategyDefeat: public CollisionStrategy {
public:
	CollisionStrategyDefeat(Board& board);
	BaseObject* handleCollision(BaseObject*, BaseObject*) override ;
private:
	Board& m_board;
};
