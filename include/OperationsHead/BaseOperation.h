#pragma once
#include <memory>

//a base class for all possible operations that can be done on board
class BaseObject;
class BaseOperation {
public:
	virtual void execute(const std::shared_ptr<BaseObject>&) = 0;
	virtual void undo(const std::shared_ptr<BaseObject>&) = 0;
};