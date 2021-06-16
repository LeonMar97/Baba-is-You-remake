#include "Rock.h" 
std::unordered_set<Attribute*>Rock::m_rockAttributes = std::unordered_set<Attribute*>();

Rock::Rock(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(rocks_t), Direction::Stay, loc, ROCK_LIGHTER_COLOR)
{
	
}

std::type_index Rock::wordTypeId() {
	return typeid(RockWord);
}

std::unordered_set<Attribute*>& Rock::getStatic() {
	return Rock::m_rockAttributes;
}
