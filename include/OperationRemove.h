#pragma once
#include "Board.h"
#include "BaseOperation.h"

class OperationRemove : public BaseOperation {
public:
	OperationRemove(Board& board) : m_board(board) {}
	void execute(const std::shared_ptr<BaseObject>& baseObj) override { m_board.removeObject(baseObj); }
	void undo(const std::shared_ptr<BaseObject>& baseObj) override { m_board.addObject(baseObj); }
private:
	Board& m_board;
};