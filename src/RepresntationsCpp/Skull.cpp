#include "Skull.h" 
std::unordered_set<Attribute*>Skull::m_skullAttributes = std::unordered_set<Attribute*>();

Skull::Skull(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(skulls_t), Direction::Stay, loc, SKULL_LIGHTER_COLOR)
{
	
}

std::type_index Skull::wordTypeId() {
	return typeid(SkullWord);
}

std::unordered_set<Attribute*>& Skull::getStatic() {
	return Skull::m_skullAttributes;
}
