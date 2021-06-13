#include"PushWord.h"
PushWord::PushWord(const sf::Vector2u& loc)
	:Attribute("Push",Resources::instance().animationData(pushword_t), Direction::Stay, loc, sf::Color(144, 103, 62))
{
	//m_character.setFillColor(sf::Color(144, 103, 62));
}
