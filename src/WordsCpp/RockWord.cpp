#include"RockWord.h"
RockWord::RockWord(const sf::Vector2u& loc)
	:Noun("Rock",Resources::instance().animationData(rockword_t), Direction::Stay, loc, 'R', rocks_t)
{
	//m_character.setFillColor(sf::Color(217,57,106));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}

void RockWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc = castToLoc(cur->returnPos());
	delete(cur);
	cur = new Rock(loc);
}
std::unordered_set<Attribute*>& RockWord::getStaticRepresentation() {
	return Rock::m_rockAttributes;
}
