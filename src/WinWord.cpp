#include"WinWord.h"
WinWord::WinWord(const sf::Vector2u& loc)
	:Attribute("Win",Textures::instance().get_Textures(winword_t), DEFAULT_IMG_COUNT, loc)
{
	m_character.setFillColor(sf::Color(144, 103, 62));
	//m_character.setOutlineThickness(1);
	//m_character.setOutlineColor(sf::Color::Red);
}
