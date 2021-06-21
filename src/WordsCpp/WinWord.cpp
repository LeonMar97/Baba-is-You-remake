#include"WinWord.h"
#include "Factory.h"

bool WinWord::m_registerit = Factory::registerit('w',
	[](const sf::Vector2u& loc, Board& board) -> PairObjData {
		auto obj = std::make_shared<WinWord>(loc, board);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});
WinWord::WinWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Win", Resources::instance().animationData(winword_t), Direction::Stay, loc,
		WIN_COLOR, WIN_LIGHTER_COLOR), m_board(board)
{
}

void WinWord::youWin() {
			m_board.endLevel();

}