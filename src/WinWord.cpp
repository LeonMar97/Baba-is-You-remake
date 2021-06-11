#include"WinWord.h"
WinWord::WinWord(const sf::Vector2u& loc)
	:Attribute("Win",Resources::instance().animationData(winword_t), Direction::Stay, loc, sf::Color(144, 103, 62))
{
	//m_character.setFillColor(sf::Color(144, 103, 62));
}
