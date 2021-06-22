#include"BabaWord.h"
#include "Factory.h"
#include "OperationTransform.h"
bool BabaWord::m_registerit = Factory::registerit('b',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<BabaWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

BabaWord::BabaWord(const sf::Vector2u& loc)
	:Noun("Baba",Resources::instance().animationData(babaword_t), Direction::Stay, loc, BABA_COLOR,
		BABA_LIGHTER_COLOR)
{}
void BabaWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Baba>(board));
}
CollisionStrategySet& BabaWord::getStaticRepresentation() {
	return Baba::m_babaAttributes;
}