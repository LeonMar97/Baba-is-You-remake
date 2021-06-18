#pragma once
#include "BaseOperation.h"

class NoOperation : public BaseOperation{
public:
	void execute(const std::shared_ptr<BaseObject>&) override{}
	void undo(const std::shared_ptr<BaseObject>&) override{}
};