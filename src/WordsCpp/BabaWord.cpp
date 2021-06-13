#include"BabaWord.h"
BabaWord::BabaWord(const sf::Vector2u& loc)
//IS ENUM NEEDED???
	:Noun("Baba",Resources::instance().animationData(babaword_t), Direction::Stay, loc, sf::Color(217, 57, 106), 'B', babas_t)
{
}

std::unordered_set<Attribute*>& BabaWord::getStatic() {
	return Baba::m_babaAtributes;
}
void BabaWord::replaceObjInLocation(BaseObject*& cur) {
	auto loc=castToLoc(cur->returnPos());
	delete(cur);
	cur = new Baba(loc);
}
