#include"PushWord.h"
PushWord::PushWord(const sf::Vector2u& loc)
	:Attribute("Push",Resources::instance().animationData(pushword_t), Direction::Stay, loc, PUSH_COLOR,
		PUSH_LIGHTER_COLOR)
{}

PushWord::PushWord()
	: Attribute("Push", Resources::instance().animationData(pushword_t), Direction::Stay, {0,0}, PUSH_COLOR,
		PUSH_LIGHTER_COLOR)
{}

bool PushWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	passiveObj->removeTopLocStack();
	passiveObj->move(activeObj->getDir());
	return true;
}
