#include "Baba.h" 
std::unordered_set<Attribute*>Baba::m_babaAtributes = std::unordered_set<Attribute*>();

Baba::Baba(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(babas_t), Direction::Right, loc)
{
	
}
