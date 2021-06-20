#pragma once
#include <Memory>
#include "DataHolder.h"
#include "BaseOperation.h"
#include "BaseObject.h"
#include <stack>
class DataHolder{
public:
	DataHolder(const std::shared_ptr<BaseObject>& baseObj);
	void execute(BaseOperation* op);
	bool undo();
	void replacePtr(const std::shared_ptr<BaseObject>& replacePtr);
	BaseOperation* lastOp();
private:
	std::shared_ptr<BaseObject> m_ptrObject;
	std::stack<BaseOperation*> m_history;
};
