#include "CollisionStrategyYou.h"

CollisionStrategyYou::CollisionStrategyYou()
	: CollisionStrategy(100) //just to make a point, whoever you are, you are always pushed. 
	//otherwise cheating might occur
{}

//same as push
BaseObject* CollisionStrategyYou::handleCollision(BaseObject * passiveObj, BaseObject * activeObj) {
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

bool CollisionStrategyYou::move(BaseObject& curYou,const Direction& dir) {
	curYou.undoOperation(); //overwrite default NoOperation that was inserted before
	curYou.executeOperation(new OperationMove(dir)); //move to the direction needed
	return true;
}
