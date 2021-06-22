#include "Flower.h" 
#include "FlowerWord.h" 
#include "Factory.h"

CollisionStrategySet Flower::m_flowerAttributes = CollisionStrategySet();
bool Flower::m_registerit = Factory::registerit('P',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Flower>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

Flower::Flower(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(flowers_t), Direction::Stay, loc, FLAG_LIGHTER_COLOR)
{}

std::type_index Flower::wordTypeId() {
	return typeid(FlowerWord);
}

CollisionStrategySet& Flower::getStatic() {
	return Flower::m_flowerAttributes;
}
