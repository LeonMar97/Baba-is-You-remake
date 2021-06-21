#include "CollisionStrategy/CollisionStrategyStop.h"

CollisionStrategyStop::CollisionStrategyStop()
	: CollisionStrategy(2)
{}

BaseObject* CollisionStrategyStop::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	activeObj->undoOperation(); //undo previous movement
	activeObj->executeOperation(new NoOperation()); //if hit a wall - act as if no operation was done
	return activeObj; //it acts as if nothing was moved at all - so no further actions are needed}
}
