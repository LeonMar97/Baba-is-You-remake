#pragma once
#include "BaseOperation.h"
#include <stack>

//class for polymorphizem..
class BaseDataHolder {
public:
	BaseDataHolder() {}
	void addToHistory(BaseOperation* op) { m_history.push(op); }
	virtual BaseObject* getPtr() = 0;
private:
	std::stack<BaseOperation*> m_history;
	std::stack<int> m_temp;
};