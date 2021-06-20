#include"Is.h"
#include "Factory.h"
bool Is::m_registerit = Factory::registerit('i',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Is>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

Is::Is(const sf::Vector2u& loc)
	:Conjunction("is",Resources::instance().animationData(is_t), Direction::Stay, loc, IS_COLOR,
	IS_LIGHTER_COLOR)
{
}