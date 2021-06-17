#include"SinkWord.h"
SinkWord::SinkWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Sink",Resources::instance().animationData(sinkword_t), Direction::Stay, loc, WATER_COLOR,
		WATER_LIGHTER_COLOR), m_board(board)
{}

bool SinkWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	m_board.removeObject(activeObj);
	m_board.removeObject(passiveObj);
	return false;
}
