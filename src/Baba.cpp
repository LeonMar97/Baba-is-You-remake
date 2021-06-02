#include "Baba.h" 

Baba::Baba()
:BaseObject(Textures::instance().get_Textures(babas_t), BABAIMGCOUNT)
{
	m_character.setFillColor(sf::Color::Red);
}
