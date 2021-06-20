#include"PushWord.h"
#include "OperationMove.h"
#include "NoOperation.h"
PushWord::PushWord(const sf::Vector2u& loc)
	:Attribute("Push",Resources::instance().animationData(pushword_t), Direction::Stay, loc, PUSH_COLOR,
		PUSH_LIGHTER_COLOR)
{}

PushWord::PushWord()
	: Attribute("Push", Resources::instance().animationData(pushword_t), Direction::Stay, {0,0}, PUSH_COLOR,
		PUSH_LIGHTER_COLOR)
{}

bool PushWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	auto lastOp = passiveObj->lastOp();
	if (dynamic_cast<NoOperation*>(lastOp)) { //must check if something happened before, otherwise weird stuff
		passiveObj->undoOperation();
		passiveObj->executeOperation(new OperationMove(activeObj->getDir()));
	}
	else {
		passiveObj->undoOperation();
		passiveObj->executeOperation(new NoOperation());
		return true;
	}
}
