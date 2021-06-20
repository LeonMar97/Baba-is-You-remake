#include"WallWord.h"
#include "Factory.h"

bool WallWord::m_registerit = Factory::registerit('k',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<WallWord>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});

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
