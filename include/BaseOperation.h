#pragma once
#include <memory>

class BaseObject;
class BaseOperation {
public:
	virtual void execute(const std::shared_ptr<BaseObject>&) = 0;
	virtual void undo(const std::shared_ptr<BaseObject>&) = 0;
};