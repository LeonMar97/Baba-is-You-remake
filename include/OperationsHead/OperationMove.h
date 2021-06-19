#pragma once
#include "Direction.h"
#include "BaseOperation.h"
#include "BaseObject.h"

//a class with a member of direction that represents movement to this certain direction
//the execute moves the object to the given direction
//undo moves it to the opposite direction

class OperationMove : public BaseOperation{
public:
	OperationMove(Direction dir);
	void execute(const std::shared_ptr<BaseObject>& baseObj) override; 
	void undo(const std::shared_ptr<BaseObject>& baseObj) override;
private:
	Direction m_dir;
};