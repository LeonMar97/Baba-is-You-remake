#pragma once
#include "Board.h"
#include "BaseOperation.h"

//a class with a member of direction that represents removing the object
//the execute moves the object to the given direction
//undo moves it to the opposite direction

class OperationRemove : public BaseOperation {
public:
	OperationRemove(Board& board);
	void execute(const std::shared_ptr<BaseObject>& baseObj) override;
	void undo(const std::shared_ptr<BaseObject>& baseObj);
private:
	Board& m_board; //there must be an interactions with the board as the adding and removing is done from there
};