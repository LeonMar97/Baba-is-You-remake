#include "PropertyYou.h"

PropertyYou::PropertyYou()
	: Property(100) //just to make a point, whoever you are, you are always pushed. 
	//otherwise cheating might occur
{
	m_movementSound.setBuffer(Resources::instance().get_Sounds(movement_t));
	m_movementSound.setVolume(30);
}

//same as push
BaseObject* PropertyYou::handleCollision(BaseObject * passiveObj, BaseObject * activeObj) {
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

bool PropertyYou::move(BaseObject& curYou,const Direction& dir) {
	curYou.undoOperation(); //overwrite default NoOperation that was inserted before
	curYou.executeOperation(new OperationMove(dir)); //move to the direction needed
	m_movementSound.play();
	return true;
}
