#include"WaterWord.h"
#include "Factory.h"

#include "OperationTransform.h"
bool WaterWord::m_registerit = Factory::registerit('m',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<WaterWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});
WaterWord::WaterWord(const sf::Vector2u& loc)
	:Noun("Water",Resources::instance().animationData(waterword_t), Direction::Stay, loc, WATER_COLOR, WATER_LIGHTER_COLOR)
{}

void WaterWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Water>(board)); //transform to water
}
CollisionStrategySet& WaterWord::getStaticRepresentation() {
	return Water::m_waterAttributes;
}
