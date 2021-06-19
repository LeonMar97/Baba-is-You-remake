#pragma once
#include <Memory>
#include "DataHolder.h"
#include "BaseOperation.h"
#include "BaseObject.h"
#include <stack>
class DataHolder{
public:
	DataHolder(const std::shared_ptr<BaseObject>& baseObj) : m_ptrObject(baseObj)
	{ m_ptrObject->initializeDataHolder(this); }
	void addToHistory(BaseOperation* op) { m_history.push(op); }
	void execute(BaseOperation* op) {
		m_history.push(op);
		op->execute(m_ptrObject);
	}
	void undo() {
		if (!m_history.empty()) {
			m_history.top()->undo(m_ptrObject);
			m_history.pop();
		}
	}

	void removeOperation() {
		if (!m_history.empty()) {
			auto op = m_history.top();
			m_history.pop();
			delete op;
		}
	}

	void replacePtr(std::shared_ptr<BaseObject>& replacePtr) { m_ptrObject = replacePtr; }

	BaseOperation* lastOp() { if (!m_history.empty()) return m_history.top(); else return nullptr; }
private:
	std::shared_ptr<BaseObject> m_ptrObject;
	std::stack<BaseOperation*> m_history;
};
