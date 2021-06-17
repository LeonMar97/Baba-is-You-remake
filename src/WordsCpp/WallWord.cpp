#include"WallWord.h"
WallWord::WallWord(const sf::Vector2u& loc)
	:Noun("Wall",Resources::instance().animationData(wallword_t), Direction::Stay, loc, WALL_COLOR, WALL_LIGHTER_COLOR)
{}

void WallWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc = castToLoc(cur->returnPos());
	delete(cur);
	cur = new Wall(loc);
}
std::unordered_set<Attribute*>& WallWord::getStaticRepresentation() {
	return Wall::m_wallAttributes;
}
