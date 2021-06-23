#include"AlgaeWord.h"
#include "Factory.h"
#include "OperationTransform.h"

bool AlgaeWord::m_registerit = Factory::registerit('a',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<AlgaeWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

AlgaeWord::AlgaeWord(const sf::Vector2u& loc)
	:Noun("Algae",Resources::instance().animationData(algaeword_t), Direction::Stay, loc, ALGAE_COLOR, ALGAE_LIGHTER_COLOR)
{}

void AlgaeWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Algae>(board));
}
PropertySet& AlgaeWord::getStaticRepresentation() {
	return Algae::m_algaeAttributes;
}
