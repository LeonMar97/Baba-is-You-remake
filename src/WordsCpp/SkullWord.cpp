#include"SkullWord.h"
#include "Factory.h"
bool SkullWord::m_registerit = Factory::registerit('g',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<SkullWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

SkullWord::SkullWord(const sf::Vector2u& loc)
	:Noun("Skull",Resources::instance().animationData(skullword_t), 
		Direction::Stay, loc, SKULL_COLOR, SKULL_LIGHTER_COLOR)
{
}

void SkullWord::replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board) {
	auto loc = castToLoc(cur->returnPos());
	cur->executeOperation(new OperationTransform<Skull>(board)); //trandform to skull
}
std::unordered_set<Attribute*>& SkullWord::getStaticRepresentation() {
	return Skull::m_skullAttributes;
}
