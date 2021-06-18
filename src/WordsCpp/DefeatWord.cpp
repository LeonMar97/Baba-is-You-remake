#include"DefeatWord.h"
DefeatWord::DefeatWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Defeat",Resources::instance().animationData(defeatword_t), Direction::Stay, loc, DEFEAT_COLOR,
		DEFEAT_LIGHTER_COLOR), m_board(board)
{
}
bool DefeatWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if (dynamic_cast<YouWord*>(atr)) {}
			//m_board.removeObject(activeObj);
	}
	return false;
}
