#include"WaterWord.h"
#include "Factory.h"

bool WaterWord::m_registerit = Factory::registerit('m',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<WaterWord>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});
WaterWord::WaterWord(const sf::Vector2u& loc)
	:Noun("Water",Resources::instance().animationData(waterword_t), Direction::Stay, loc, WATER_COLOR, WATER_LIGHTER_COLOR)
{}

void WaterWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Water>(board)); //transform to water
}
std::unordered_set<Attribute*>& WaterWord::getStaticRepresentation() {
	return Water::m_waterAttributes;
}
