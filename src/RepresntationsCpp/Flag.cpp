#include "Flag.h" 
#include "Factory.h"
std::unordered_set<Attribute*>Flag::m_flagAttributes = std::unordered_set<Attribute*>();
bool Flag::m_registerit = Factory::registerit('F',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<Flag>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});

Flag::Flag(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(flags_t), Direction::Stay, loc, FLAG_LIGHTER_COLOR)
{}

std::type_index Flag::wordTypeId() {
	return typeid(FlagWord);
}

std::unordered_set<Attribute*>& Flag::getStatic() {
	return Flag::m_flagAttributes;
}
