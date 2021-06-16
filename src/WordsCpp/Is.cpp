#include"Is.h"
Is::Is(const sf::Vector2u& loc)
	:Conjunction("is",Resources::instance().animationData(is_t), Direction::Stay, loc, sf::Color(115, 115, 115),
	sf::Color::Red)
{
	//m_character.setFillColor(sf::Color(115, 115, 115));
}