#include"RockWord.h"
RockWord::RockWord(const sf::Vector2u& loc)
	:Noun("Rock",Textures::instance().get_Textures(/*!!!!!!!*/rocks_t), DEFAULT_IMG_COUNT, loc, 'R', rocks_t)
{
	m_character.setFillColor(sf::Color(217,57,106));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}

std::unordered_set<Attribute*>& RockWord::getStatic() {
	return Rock::m_rockAtributes;
}
