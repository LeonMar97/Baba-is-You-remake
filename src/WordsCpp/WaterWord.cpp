#include"WaterWord.h"
WaterWord::WaterWord(const sf::Vector2u& loc)
	:Noun("Water",Resources::instance().animationData(waterword_t), Direction::Stay, loc, WATER_COLOR, WATER_LIGHTER_COLOR)
{}

void WaterWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc = castToLoc(cur->returnPos());
	delete(cur);
	cur = new Water(loc);
}
std::unordered_set<Attribute*>& WaterWord::getStaticRepresentation() {
	return Water::m_waterAttributes;
}
