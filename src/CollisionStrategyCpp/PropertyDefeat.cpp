#include "PropertyDefeat.h"

PropertyDefeat::PropertyDefeat(Board& board)
	: Property(0), m_board(board)
{}

BaseObject* PropertyDefeat::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if (dynamic_cast<PropertyYou*>(atr.get())) {
			activeObj->undoOperation(); //for making character appear one step before defeat after undo
			activeObj->executeOperation(new OperationRemove(m_board));
		}
	}
	return nullptr;
}
