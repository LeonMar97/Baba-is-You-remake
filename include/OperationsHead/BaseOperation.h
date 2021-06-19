#pragma once
#include <memory>

//a base class for all possible operations that can be done on board
class BaseObject;
class BaseOperation {
public:
	virtual void execute(std::shared_ptr<BaseObject>&) = 0;
	virtual void undo(std::shared_ptr<BaseObject>&) = 0;
};