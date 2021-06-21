#pragma once
#include "CollisionStrategy.h"
#include "WordsHead/YouWord.h"
#include "Board.h"

class CollisionStrategyWin: public CollisionStrategy {
public:
	CollisionStrategyWin(Board& board);
	BaseObject* handleCollision(BaseObject*, BaseObject*);
private:
	Board& m_board;
};
