#include "Wall.h" 
std::unordered_set<Attribute*>Wall::m_wallAttributes = std::unordered_set<Attribute*>();

Wall::Wall(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(walls_t), Direction::Stay, loc, WALL_COLOR)
{
	
}

std::type_index Wall::wordTypeId() {
	return typeid(WallWord);
}

std::unordered_set<Attribute*>& Wall::getStatic() {
	return Wall::m_wallAttributes;
}
