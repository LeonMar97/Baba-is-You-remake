#include"SinkWord.h"
#include "OperationRemove.h"
#include "OperationMove.h"

SinkWord::SinkWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Sink",Resources::instance().animationData(sinkword_t), Direction::Stay, loc, WATER_COLOR,
		WATER_LIGHTER_COLOR), m_board(board)
{}

bool SinkWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	activeObj->undoOperation(); //for active object positioning after redo
	//remove both objects from board using operationRemove
	activeObj->executeOperation(new OperationRemove(m_board)); 
	passiveObj->executeOperation(new OperationRemove(m_board));
	return false;
}
