#include"BabaWord.h"
BabaWord::BabaWord(const sf::Vector2u& loc)
	:Noun("Baba",Textures::instance().get_Textures(babaword_t), DEFAULT_IMG_COUNT, loc)
{
	m_character.setFillColor(sf::Color(217,57,106));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}

std::unordered_set<Attribute*>& BabaWord::getStatic() {
	
	return Baba::m_babaAtributes;
}
