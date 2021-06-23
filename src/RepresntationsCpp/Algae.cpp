#include "Algae.h" 
#include "AlgaeWord.h" 
#include "Factory.h"

PropertySet Algae::m_algaeAttributes = PropertySet();
bool Algae::m_registerit = Factory::registerit('A',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Algae>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

Algae::Algae(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(algae_t), Direction::Stay, loc, ALGAE_LIGHTER_COLOR)
{}

std::type_index Algae::wordTypeId() {
	return typeid(AlgaeWord);
}

PropertySet& Algae::getStatic() {
	return Algae::m_algaeAttributes;
}
