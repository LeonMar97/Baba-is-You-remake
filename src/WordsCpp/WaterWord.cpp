#include"WaterWord.h"
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
