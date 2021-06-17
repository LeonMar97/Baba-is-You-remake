#include"Is.h"
Is::Is(const sf::Vector2u& loc)
	:Conjunction("is",Resources::instance().animationData(is_t), Direction::Stay, loc, IS_COLOR,
	IS_LIGHTER_COLOR)
{
}