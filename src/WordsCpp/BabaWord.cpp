#include"BabaWord.h"
BabaWord::BabaWord(const sf::Vector2u& loc)
	:Noun("Baba",Resources::instance().animationData(babaword_t), Direction::Stay, loc, BABA_COLOR,
		BABA_LIGHTER_COLOR)
{}
void BabaWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Baba>(board));
}
std::unordered_set<Attribute*>& BabaWord::getStaticRepresentation() {
	return Baba::m_babaAttributes;
}