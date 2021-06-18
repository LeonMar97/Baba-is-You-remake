#pragma once
#include "Board.h"
#include "BaseOperation.h"

class OperationRemove : public BaseOperation {
public:
	OperationRemove(Board& board) : m_board(board) {}
	void execute(BaseObject* baseObj) override { m_board.removeObject(baseObj); }
	void undo(BaseObject* baseObj) override { m_board.addObject(baseObj); }
private:
	Board& m_board;
};