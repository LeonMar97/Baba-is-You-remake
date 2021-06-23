#include "Flag.h" 
#include "FlagWord.h" 
#include "Factory.h"

PropertySet Flag::m_flagAttributes = PropertySet();
bool Flag::m_registerit = Factory::registerit('F',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Flag>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

Flag::Flag(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(flags_t), Direction::Stay, loc, FLAG_LIGHTER_COLOR)
{}

std::type_index Flag::wordTypeId() {
	return typeid(FlagWord);
}

PropertySet& Flag::getStatic() {
	return Flag::m_flagAttributes;
}
