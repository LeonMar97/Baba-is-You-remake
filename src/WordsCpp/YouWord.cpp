#include"YouWord.h"
#include "OperationMove.h"
YouWord::YouWord(const sf::Vector2u& loc)
	:Attribute("You",Resources::instance().animationData(youword_t), Direction::Stay, loc,
		YOU_COLOR, YOU_LIGHTER_COLOR)
{
}
bool YouWord::move(BaseObject& curYou,const Direction& dir) {
	curYou.undoOperation();
	curYou.executeOperation(new OperationMove(dir));
	return true;
}

void YouWord::putRuleIntoAffect(Noun& noun) {
	Attribute::putRuleIntoAffect(noun);
	noun.fillAttributes(&m_pushOfYou);
}
void YouWord::deleteRule(Noun& noun){
	Attribute::deleteRule(noun);
	noun.removeAttribute(&m_pushOfYou);
}
