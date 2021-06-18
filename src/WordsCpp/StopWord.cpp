#include"StopWord.h"
StopWord::StopWord(const sf::Vector2u& loc)
	:Attribute("Stop",Resources::instance().animationData(stopword_t), Direction::Stay, loc, STOP_COLOR,
		STOP_LIGHTER_COLOR)
{
}
StopWord::StopWord()
	: Attribute("Stop", Resources::instance().animationData(stopword_t), Direction::Stay, {0,0}, sf::Color(144, 103, 62),
		sf::Color::Red)
{}

bool StopWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	//activeObj->undoOperation();
	activeObj->undoOperation();
	//activeObj->move(opposite(activeObj->getDir()));
	return false; //it acts as if nothing was moved at all - so no further actions are needed
}
