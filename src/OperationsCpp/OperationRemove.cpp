#include "OperationRemove.h"

OperationRemove::OperationRemove(Board& board) 
	: m_board(board)
{}
	void OperationRemove::execute(std::shared_ptr<BaseObject>& baseObj) {
		m_board.removeObject(baseObj); 
}
void OperationRemove::undo(std::shared_ptr<BaseObject>& baseObj) {
	m_board.addObject(baseObj); 
}
