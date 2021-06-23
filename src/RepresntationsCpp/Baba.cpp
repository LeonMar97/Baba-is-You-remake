#include "Baba.h" 
#include "BabaWord.h" 
#include "Factory.h"
PropertySet Baba::m_babaAttributes = PropertySet();

bool Baba::m_registerit = Factory::registerit('B',
	[](const sf::Vector2u& loc, Board&) -> PairObjData { 
		auto obj = std::make_shared<Baba>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});


Baba::Baba(const sf::Vector2u& loc)
	:BaseObject(
		Resources::instance().animationData(babas_t),
		Resources::instance().animationData(babas1_t),
		Resources::instance().animationData(babas2_t),
		Resources::instance().animationData(babas3_t),
		Direction::Right, loc, sf::Color::White)
{}
std::type_index Baba::wordTypeId() {
	return typeid(BabaWord);
}

PropertySet& Baba::getStatic() {
	return Baba::m_babaAttributes;
}
