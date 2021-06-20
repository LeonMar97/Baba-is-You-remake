#include"YouWord.h"
#include "OperationMove.h"
YouWord::YouWord(const sf::Vector2u& loc)
	:Attribute("You",Resources::instance().animationData(youword_t), Direction::Stay, loc,
		YOU_COLOR, YOU_LIGHTER_COLOR)
{
}
bool YouWord::move(BaseObject& curYou,const Direction& dir) {
	curYou.undoOperation(); //overwrite default NoOperation that was inserted before
	curYou.executeOperation(new OperationMove(dir)); //move to the direction needed
	return true;
}

void YouWord::putRuleIntoAffect(Noun& noun) {
	Attribute::putRuleIntoAffect(noun);
	noun.fillAttributes(&m_pushOfYou); //"you" is always pushed, otherwise cheating might occur
}
void YouWord::deleteRule(Noun& noun){
	Attribute::deleteRule(noun);
	noun.removeAttribute(&m_pushOfYou);
}
