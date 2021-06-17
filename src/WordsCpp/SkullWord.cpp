#include"SkullWord.h"
SkullWord::SkullWord(const sf::Vector2u& loc)
	:Noun("Skull",Resources::instance().animationData(skullword_t), Direction::Stay, loc, SKULL_COLOR, SKULL_LIGHTER_COLOR)
{
}

void SkullWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc = castToLoc(cur->returnPos());
	delete(cur);
	cur = new Skull(loc);
}
std::unordered_set<Attribute*>& SkullWord::getStaticRepresentation() {
	return Skull::m_skullAttributes;
}
