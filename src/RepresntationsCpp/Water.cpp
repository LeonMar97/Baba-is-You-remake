#include "Water.h" 
std::unordered_set<Attribute*>Water::m_waterAttributes = std::unordered_set<Attribute*>();

Water::Water(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(water_t), Direction::Stay, loc, WATER_LIGHTER_COLOR)
{
	
}

std::type_index Water::wordTypeId() {
	return typeid(WaterWord);
}

std::unordered_set<Attribute*>& Water::getStatic() {
	return Water::m_waterAttributes;
}
