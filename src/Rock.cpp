#include "Rock.h" 
std::unordered_set<Attribute*>Rock::m_rockAtributes = std::unordered_set<Attribute*>();

Rock::Rock(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(rocks_t), Direction::Stay, loc)
{
	
}
