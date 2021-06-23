#include "OperationRemove.h"

OperationRemove::OperationRemove(Board& board) 
	: m_board(board)
{}
	void OperationRemove::execute(std::shared_ptr<BaseObject>& baseObj) {
		m_board.removeObject(baseObj); 
}
void OperationRemove::undo(std::shared_ptr<BaseObject>& baseObj) {
	baseObj->undoOperation(); //if removed, it was duo to movement. undo this movement
	m_board.addObject(baseObj); 
}
