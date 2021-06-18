#pragma once

class BaseObject;
class BaseOperation {
public:
	virtual void execute(BaseObject*) = 0;
	virtual void undo(BaseObject*) = 0;
};