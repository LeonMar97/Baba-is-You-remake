#include "CollisionStrategy/CollisionStrategySink.h"
CollisionStrategySink::CollisionStrategySink()
	: CollisionStrategy(1)
{}

BaseObject* CollisionStrategySink::handleCollision(BaseObject * passiveObj, BaseObject * activeObj) {
	activeObj->undoOperation(); //for active object positioning after redo
	//remove both objects from board using operationRemove
	activeObj->executeOperation(new OperationRemove(m_board));
	passiveObj->executeOperation(new OperationRemove(m_board));
	return nullptr;
}
