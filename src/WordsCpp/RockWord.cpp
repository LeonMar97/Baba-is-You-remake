#include"RockWord.h"
RockWord::RockWord(const sf::Vector2u& loc)
	:Noun("Rock",Resources::instance().animationData(rockword_t), Direction::Stay, loc, ROCK_COLOR, ROCK_LIGHTER_COLOR)
{
}

void RockWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Rock>());
}
std::unordered_set<Attribute*>& RockWord::getStaticRepresentation() {
	return Rock::m_rockAttributes;
}
