#include "Rock.h" 
#include "RockWord.h" 
#include "Factory.h"
PropertySet Rock::m_rockAttributes = PropertySet();
bool Rock::m_registerit = Factory::registerit('R', 
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Rock>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

Rock::Rock(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(rocks_t), Direction::Stay, loc, ROCK_LIGHTER_COLOR)
{
	
}

std::type_index Rock::wordTypeId() {
	return typeid(RockWord);
}

PropertySet& Rock::getStatic() {
	return Rock::m_rockAttributes;
}
