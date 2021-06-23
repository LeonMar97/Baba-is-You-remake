#include"FlowerWord.h"
#include "Factory.h"
#include "OperationTransform.h"

bool FlowerWord::m_registerit = Factory::registerit('p',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<FlowerWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

FlowerWord::FlowerWord(const sf::Vector2u& loc)
	:Noun("Flower",Resources::instance().animationData(flowerword_t), Direction::Stay, loc, FLAG_COLOR, FLAG_LIGHTER_COLOR)
{}

void FlowerWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Flower>(board));
}
PropertySet& FlowerWord::getStaticRepresentation() {
	return Flower::m_flowerAttributes;
}
