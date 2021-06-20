#include"Is.h"
#include "Factory.h"
bool Is::m_registerit = Factory::registerit('i',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<Is>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});

Is::Is(const sf::Vector2u& loc)
	:Conjunction("is",Resources::instance().animationData(is_t), Direction::Stay, loc, IS_COLOR,
	IS_LIGHTER_COLOR)
{
}