#include"BabaWord.h"
BabaWord::BabaWord(const sf::Vector2u& loc)
	:Noun("Baba",Textures::instance().get_Textures(babaword_t), DEFAULT_IMG_COUNT, loc)
{
	m_character.setFillColor(sf::Color(0x80, 0x80, 0x80));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}
