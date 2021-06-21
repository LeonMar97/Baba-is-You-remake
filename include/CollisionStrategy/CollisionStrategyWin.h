#pragma once
#include "CollisionStrategy.h"
#include "WordsHead/YouWord.h"

class CollisionStrategyWin: public CollisionStrategy {
public:
	CollisionStrategyWin();
	BaseObject* handleCollision(BaseObject*, BaseObject*)
};
