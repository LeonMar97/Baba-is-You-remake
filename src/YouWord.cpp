#include"YouWord.h"
YouWord::YouWord(const sf::Vector2u& loc)
	:Attribute("You",Textures::instance().get_Textures(youword_t), DEFAULT_IMG_COUNT, loc, youword_t)
{
	m_character.setFillColor(sf::Color(217,57,106));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}
