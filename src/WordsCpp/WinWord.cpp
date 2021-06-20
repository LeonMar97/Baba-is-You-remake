#include"WinWord.h"
#include "Factory.h"

bool WinWord::m_registerit = Factory::registerit('w',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<WinWord>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});
WinWord::WinWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Win", Resources::instance().animationData(winword_t), Direction::Stay, loc,
		WIN_COLOR, WIN_LIGHTER_COLOR), m_board(board)
{
}

bool WinWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	
	for (auto& atr : activeObj->getStatic()) {
		if(dynamic_cast<YouWord*>(atr))  //only you can win, dynamic cast is needed
			m_board.endLevel();
	}
	return false; //no more collision detections are needed
}
void WinWord::youWin() {
			m_board.endLevel();

}