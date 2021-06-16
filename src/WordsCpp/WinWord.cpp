#include"WinWord.h"
WinWord::WinWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Win", Resources::instance().animationData(winword_t), Direction::Stay, loc,
		WIN_COLOR, WIN_LIGHTER_COLOR), m_board(board)
{
}

bool WinWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if(dynamic_cast<YouWord*>(atr))
			m_board.endLevel();
	}
	return true;
}
