#include"StopWord.h"
StopWord::StopWord(const sf::Vector2u& loc)
	:Attribute("Stop",Resources::instance().animationData(stopword_t), Direction::Stay, loc, sf::Color(144, 103, 62))
{
	//m_character.setFillColor(sf::Color(144, 103, 62));
}
StopWord::StopWord()
	: Attribute("Stop", Resources::instance().animationData(stopword_t), Direction::Stay, {0,0}, sf::Color(144, 103, 62))
{
	//m_character.setFillColor(sf::Color(144, 103, 62));
}

void StopWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	activeObj->move(sf::Vector2i((activeObj->returnPos() - activeObj->returnLastPos()) / -OBJECT_SIZE));
}
