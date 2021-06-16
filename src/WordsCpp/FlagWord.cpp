#include"FlagWord.h"
FlagWord::FlagWord(const sf::Vector2u& loc)
	:Noun("Flag",Resources::instance().animationData(flagword_t), Direction::Stay, loc, ROCK_COLOR, ROCK_LIGHTER_COLOR)
{}

void FlagWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc = castToLoc(cur->returnPos());
	delete(cur);
	cur = new Flag(loc);
}
std::unordered_set<Attribute*>& FlagWord::getStaticRepresentation() {
	return Flag::m_flagAttributes;
}
