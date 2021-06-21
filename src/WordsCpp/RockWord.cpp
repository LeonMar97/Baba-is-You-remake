#include"RockWord.h"
#include "Factory.h"

bool RockWord::m_registerit = Factory::registerit('r',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<RockWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});
RockWord::RockWord(const sf::Vector2u& loc)
	:Noun("Rock",Resources::instance().animationData(rockword_t), Direction::Stay, loc, ROCK_COLOR, ROCK_LIGHTER_COLOR)
{
}

void RockWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Rock>(board));
}
CollisionStrategySet& RockWord::getStaticRepresentation() {
	return Rock::m_rockAttributes;
}
