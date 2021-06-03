#include"Is.h"
Is::Is(const sf::Vector2u& loc)
	:Conjunction("is",Textures::instance().get_Textures(is_t), DEFAULT_IMG_COUNT, loc)
	
{
	m_character.setOutlineThickness(1);
	m_character.setOutlineColor(sf::Color::Red);
}