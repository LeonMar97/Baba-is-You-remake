#include"BabaWord.h"
BabaWord::BabaWord(const sf::Vector2u& loc)
	:Noun("Baba",Resources::instance().animationData(babaword_t), Direction::Stay, loc, BABA_COLOR,
		BABA_LIGHTER_COLOR)
{}
void BabaWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc=castToLoc(cur->returnPos());
	delete(cur);
	cur = new Baba(loc);
}
std::unordered_set<Attribute*>& BabaWord::getStaticRepresentation() {
	return Baba::m_babaAttributes;
}