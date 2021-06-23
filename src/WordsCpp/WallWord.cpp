#include"WallWord.h"
#include "Factory.h"
#include "OperationTransform.h"

bool WallWord::m_registerit = Factory::registerit('k',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<WallWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

WallWord::WallWord(const sf::Vector2u& loc)
	:Noun("Wall",Resources::instance().animationData(wallword_t), Direction::Stay, loc, WALL_COLOR, WALL_LIGHTER_COLOR)
{}

void WallWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Wall>(board)); //transform to wall
}
PropertySet& WallWord::getStaticRepresentation() {
	return Wall::m_wallAttributes;
}
