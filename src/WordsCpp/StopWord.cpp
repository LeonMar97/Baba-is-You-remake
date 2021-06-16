#include"StopWord.h"
StopWord::StopWord(const sf::Vector2u& loc)
	:Attribute("Stop",Resources::instance().animationData(stopword_t), Direction::Stay, loc, STOP_COLOR,
		STOP_LIGHTER_COLOR)
{
}
StopWord::StopWord()
	: Attribute("Stop", Resources::instance().animationData(stopword_t), Direction::Stay, {0,0}, sf::Color(144, 103, 62),
		sf::Color::Red)
{
	//m_character.setFillColor(sf::Color(144, 103, 62));
}

bool StopWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	activeObj->move(opposite(activeObj->getDir()));
	//activeObj->move(sf::Vector2i((activeObj->returnPos() - activeObj->returnLastPos()) / -OBJECT_SIZE));
	return true;
}
