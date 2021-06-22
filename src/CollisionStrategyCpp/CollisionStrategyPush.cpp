#include "CollisionStrategyPush.h"

CollisionStrategyPush::CollisionStrategyPush()
	: CollisionStrategy(2)
{}

BaseObject* CollisionStrategyPush::handleCollision(BaseObject * passiveObj, BaseObject * activeObj) {
	auto lastOp = passiveObj->lastOp();
	//check if what is pushed has been moved before - if not, move it
	if (dynamic_cast<NoOperation*>(lastOp)) { //must check if something happened before, otherwise weird stuff
		passiveObj->undoOperation();
		passiveObj->executeOperation(new OperationMove(activeObj->getDir()));
	}
	 else { //else, what is pushed has been pushed before - meaning it hit stop. 
		passiveObj->undoOperation();
		passiveObj->executeOperation(new NoOperation());
	}
	return passiveObj; //either way passive object is the one that has changed state
}