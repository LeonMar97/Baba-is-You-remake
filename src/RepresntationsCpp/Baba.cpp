#include "Baba.h" 
std::unordered_set<Attribute*>Baba::m_babaAtributes = std::unordered_set<Attribute*>();

Baba::Baba(const sf::Vector2u& loc)
:BaseObject(Textures::instance().get_Textures(babas_t), BABA_IMG_COUNT, loc)
{
	
}
