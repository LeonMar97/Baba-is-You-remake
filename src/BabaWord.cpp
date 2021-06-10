#include"BabaWord.h"
BabaWord::BabaWord(const sf::Vector2u& loc)
//IS ENUM NEEDED???
	:Noun("Baba",Resources::instance().animationData(babaword_t), Direction::Stay, loc, 'B', babas_t)
{
	//m_character.setFillColor(sf::Color(217,57,106));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}

std::unordered_set<Attribute*>& BabaWord::getStatic() {
	return Baba::m_babaAtributes;
}
