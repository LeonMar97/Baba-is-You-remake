#include "Wall.h" 
#include "WallWord.h" 
#include "Factory.h"
PropertySet Wall::m_wallAttributes = PropertySet();
bool Wall::m_registerit = Factory::registerit('K',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<Wall>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

Wall::Wall(const sf::Vector2u& loc)
:BaseObject(Resources::instance().animationData(walls_t), Direction::Stay, loc, WALL_LIGHTER_COLOR)
{
	
}

std::type_index Wall::wordTypeId() {
	return typeid(WallWord);
}

PropertySet& Wall::getStatic() {
	return Wall::m_wallAttributes;
}
