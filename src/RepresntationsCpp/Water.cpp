#include "Water.h" 
#include "WaterWord.h" 
#include "Factory.h"
PropertySet Water::m_waterAttributes = PropertySet();
bool Water::m_registerit = Factory::registerit('M',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Water>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

Water::Water(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(water_t), Direction::Stay, loc, WATER_LIGHTER_COLOR)
{
	
}

std::type_index Water::wordTypeId() {
	return typeid(WaterWord);
}

PropertySet& Water::getStatic() {
	return Water::m_waterAttributes;
}
