#include "PropertyDefeat.h"

PropertyDefeat::PropertyDefeat(Board& board)
	: Property(0), m_board(board)
{}

BaseObject* PropertyDefeat::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& proprty: activeObj->getStatic()) {
		if (dynamic_cast<PropertyYou*>(proprty.get())) {
			activeObj->undoOperation(); //for making character appear one step before defeat after undo
			activeObj->executeOperation(new OperationRemove(m_board));
		}
	}
	return nullptr;
}
