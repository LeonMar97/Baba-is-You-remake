#include "CollisionStrategyDefeat.h"

CollisionStrategyDefeat::CollisionStrategyDefeat(Board& board)
	: CollisionStrategy(0), m_board(board)
{}

BaseObject* CollisionStrategyDefeat::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if (dynamic_cast<CollisionStrategyYou*>(atr.get())) {
			activeObj->undoOperation(); //for making character appear one step before defeat after undo
			activeObj->executeOperation(new OperationRemove(m_board));
		}
	}
	return nullptr;
}
