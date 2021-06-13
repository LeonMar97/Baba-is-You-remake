#include "Baba.h" 
std::unordered_set<Attribute*>Baba::m_babaAttributes = std::unordered_set<Attribute*>();

Baba::Baba(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(babas_t), Direction::Right, loc)
{
	
}
std::type_index Baba::wordTypeId() {
	return typeid(BabaWord);
}


std::unordered_set<Attribute*>& Baba::getStatic() {
	return Baba::m_babaAttributes;
}
