#pragma once
#include "BaseOperation.h"

// operation that does nothing - indicates that nothing has happened to object
class NoOperation : public BaseOperation{
public:
	void execute(std::shared_ptr<BaseObject>&) override;
	void undo(std::shared_ptr<BaseObject>&) override;
};