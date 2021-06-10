#include"YouWord.h"
YouWord::YouWord(const sf::Vector2u& loc)
	:Attribute("You",Resources::instance().animationData(youword_t), Direction::Stay, loc)
{
	//m_character.setFillColor(sf::Color(217,57,106));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}
