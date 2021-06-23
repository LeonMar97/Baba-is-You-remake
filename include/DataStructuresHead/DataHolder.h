#pragma once
#include <Memory>
#include "DataHolder.h"
#include "BaseOperation.h"
#include "BaseObject.h"
#include <stack>

// a class that holds information that BaseObject doesnt care about as an entity
//there is a need for a data structure that will hold ALL characters in current level
//and a data structure to be interacted with, and there is no point in holding two vectors
//that hold basically same information with different redundant members.

//this class holds the history of the object

class DataHolder{
public:
	DataHolder(const std::shared_ptr<BaseObject>& baseObj);
	void execute(BaseOperation* op);
	bool undo(); //returns true if the operation is done, false if empty histroy
	void replacePtr(const std::shared_ptr<BaseObject>& replacePtr);
	void removeLastOperation();
	BaseOperation* lastOp();
	~DataHolder();
private:
	std::shared_ptr<BaseObject> m_ptrObject;
	std::stack<BaseOperation*> m_history;
};
