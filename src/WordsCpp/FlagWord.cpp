#include"FlagWord.h"
#include "Factory.h"

bool FlagWord::m_registerit = Factory::registerit('f',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<FlagWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

FlagWord::FlagWord(const sf::Vector2u& loc)
	:Noun("Flag",Resources::instance().animationData(flagword_t), Direction::Stay, loc, FLAG_COLOR, FLAG_LIGHTER_COLOR)
{}

void FlagWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Flag>(board));
}
std::unordered_set<Attribute*>& FlagWord::getStaticRepresentation() {
	return Flag::m_flagAttributes;
}
