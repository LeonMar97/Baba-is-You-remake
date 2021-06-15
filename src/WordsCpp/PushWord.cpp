#include"PushWord.h"
PushWord::PushWord(const sf::Vector2u& loc)
	:Attribute("Push",Resources::instance().animationData(pushword_t), Direction::Stay, loc, sf::Color(144, 103, 62))
{
	//m_character.setFillColor(sf::Color(144, 103, 62));
}
PushWord::PushWord()
	: Attribute("Push", Resources::instance().animationData(pushword_t), Direction::Stay, {0,0}, sf::Color(144, 103, 62))
{
	//m_character.setFillColor(sf::Color(144, 103, 62));
}

bool PushWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	passiveObj->move(activeObj->getDir());
	//passiveObj->move((sf::Vector2i((activeObj->returnPos() - activeObj->returnLastPos()) / OBJECT_SIZE)));
	return true;
	//passiveObj->move({ -5, 0 });
}
