#pragma once
#include "Direction.h"
#include "BaseOperation.h"
#include "BaseObject.h"

class OperationMove : public BaseOperation{
public:
	OperationMove(Direction dir) : m_dir(dir) {}
	void execute(BaseObject* baseObj) override { baseObj->move(m_dir); }
	void undo(BaseObject* baseObj) override { baseObj->move(opposite(m_dir)); }
private:
	Direction m_dir;
};