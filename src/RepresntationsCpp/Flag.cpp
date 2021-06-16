#include "Flag.h" 
std::unordered_set<Attribute*>Flag::m_flagAttributes = std::unordered_set<Attribute*>();

Flag::Flag(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(flags_t), Direction::Stay, loc, ROCK_LIGHTER_COLOR)
{}

std::type_index Flag::wordTypeId() {
	return typeid(FlagWord);
}

std::unordered_set<Attribute*>& Flag::getStatic() {
	return Flag::m_flagAttributes;
}
