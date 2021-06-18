#include"SinkWord.h"
#include "OperationRemove.h"
#include "OperationMove.h"

SinkWord::SinkWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Sink",Resources::instance().animationData(sinkword_t), Direction::Stay, loc, WATER_COLOR,
		WATER_LIGHTER_COLOR), m_board(board)
{}

bool SinkWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	activeObj->undoOperation();
	//if(dynamic_cast<OperationMove*>(activeObj)) activeObj->undoOperation();
	activeObj->executeOperation(new OperationRemove(m_board));
	passiveObj->executeOperation(new OperationRemove(m_board));
	return false;
}
