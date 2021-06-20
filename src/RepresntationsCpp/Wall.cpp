#include "Wall.h" 
#include "Factory.h"
std::unordered_set<Attribute*>Wall::m_wallAttributes = std::unordered_set<Attribute*>();
bool Wall::m_registerit = Factory::registerit('K',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<Wall>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});

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
