#include"YouWord.h"
#include "OperationMove.h"
#include "Factory.h"

bool YouWord::m_registerit = Factory::registerit('y',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<YouWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});
YouWord::YouWord(const sf::Vector2u& loc)
	:Attribute("You",Resources::instance().animationData(youword_t), Direction::Stay, loc,
		YOU_COLOR, YOU_LIGHTER_COLOR, std::make_shared<CollisionStrategyYou>())
{}

void YouWord::putRuleIntoAffect(Noun& noun) {
	Attribute::putRuleIntoAffect(noun);
	//noun.fillAttributes(&m_pushOfYou); //"you" is always pushed, otherwise cheating might occur
}
void YouWord::deleteRule(Noun& noun){
	Attribute::deleteRule(noun);
	//noun.removeAttribute(&m_pushOfYou);
}
