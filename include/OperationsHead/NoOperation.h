#pragma once
#include "BaseOperation.h"

// operation that does nothing - indicates that nothing has happened to object
class NoOperation : public BaseOperation{
public:
	void execute(const std::shared_ptr<BaseObject>&) override;
	void undo(const std::shared_ptr<BaseObject>&) override;
};