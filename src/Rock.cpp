#include "Rock.h" 
std::unordered_set<Attribute*>Rock::m_rockAtributes = std::unordered_set<Attribute*>();

Rock::Rock(const sf::Vector2u& loc)
:BaseObject(Textures::instance().get_Textures(rocks_t), DEFAULT_IMG_COUNT, loc)
{
	
}
