#include "CollisionStrategySink.h"
CollisionStrategySink::CollisionStrategySink(Board& board)
	: CollisionStrategy(1), m_board(board)
{}

BaseObject* CollisionStrategySink::handleCollision(BaseObject * passiveObj, BaseObject * activeObj) {
	activeObj->undoOperation(); //for active object positioning after redo
	//remove both objects from board using operationRemove
	activeObj->executeOperation(new OperationRemove(m_board));
	passiveObj->executeOperation(new OperationRemove(m_board));
	return nullptr;
}
