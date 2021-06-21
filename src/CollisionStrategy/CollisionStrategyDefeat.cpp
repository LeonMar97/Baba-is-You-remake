#include "CollisionStrategy/CollisionStrategyDefeat.h"

CollisionStrategyDefeat::CollisionStrategyDefeat()
	: CollisionStrategy(0)
{}

BaseObject* CollisionStrategyDefeat::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if (dynamic_cast<YouWord*>(atr)) {
			activeObj->undoOperation(); //for making character appear one step before defeat after undo
			activeObj->executeOperation(new OperationRemove(m_board));
		}
	}
	return nullptr;
}
