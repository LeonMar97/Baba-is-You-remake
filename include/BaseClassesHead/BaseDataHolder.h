#pragma once
#include "BaseOperation.h"
#include <stack>

//class for polymorphizem..
class BaseDataHolder {
public:
	BaseDataHolder() {}
private:
	std::stack<int> m_temp;
};