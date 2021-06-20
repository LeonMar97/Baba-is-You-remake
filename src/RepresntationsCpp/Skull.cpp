#include "Skull.h" 
#include "Factory.h"
std::unordered_set<Attribute*>Skull::m_skullAttributes = std::unordered_set<Attribute*>();
bool Skull::m_registerit = Factory::registerit('G', 
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Skull>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

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
