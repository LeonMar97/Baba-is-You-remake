#include"WallWord.h"
WallWord::WallWord(const sf::Vector2u& loc)
	:Noun("Wall",Resources::instance().animationData(wallword_t), Direction::Stay, loc, WALL_COLOR, WALL_LIGHTER_COLOR)
{}

void WallWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Wall>(board)); //transform to wall
}
std::unordered_set<Attribute*>& WallWord::getStaticRepresentation() {
	return Wall::m_wallAttributes;
}
