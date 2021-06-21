#include "CollisionStrategyPush.h"

CollisionStrategyPush::CollisionStrategyPush()
	: CollisionStrategy(2)
{}

BaseObject* CollisionStrategyPush::handleCollision(BaseObject * passiveObj, BaseObject * activeObj) {
	auto lastOp = passiveObj->lastOp();
	if (dynamic_cast<NoOperation*>(lastOp)) { //must check if something happened before, otherwise weird stuff
		passiveObj->undoOperation();
		passiveObj->executeOperation(new OperationMove(activeObj->getDir()));
	}
	 else {
		passiveObj->undoOperation();
		passiveObj->executeOperation(new NoOperation());
	}
	return passiveObj;
}