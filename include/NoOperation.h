#pragma once
#include "BaseOperation.h"

class NoOperation : public BaseOperation{
public:
	void execute(BaseObject*) override{}
	void undo(BaseObject*) override{}
};