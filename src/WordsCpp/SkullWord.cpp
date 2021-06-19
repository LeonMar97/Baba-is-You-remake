#include"SkullWord.h"
SkullWord::SkullWord(const sf::Vector2u& loc)
	:Noun("Skull",Resources::instance().animationData(skullword_t), Direction::Stay, loc, SKULL_COLOR, SKULL_LIGHTER_COLOR)
{
}

void SkullWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Skull>(board));
}
std::unordered_set<Attribute*>& SkullWord::getStaticRepresentation() {
	return Skull::m_skullAttributes;
}
