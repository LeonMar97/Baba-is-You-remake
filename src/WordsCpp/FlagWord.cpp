#include"FlagWord.h"
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
