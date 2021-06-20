#include "DataHolder.h"
DataHolder::DataHolder(const std::shared_ptr<BaseObject>& baseObj) : m_ptrObject(baseObj){
	m_ptrObject->initializeDataHolder(this); 
}
void DataHolder::execute(BaseOperation* op) {
	m_history.push(op);
	op->execute(m_ptrObject);
}
bool DataHolder::undo() {
	if (!m_history.empty()) {
		m_history.top()->undo(m_ptrObject);
		m_history.pop();
		return true;
	}
	return false;
}

void DataHolder::replacePtr(const std::shared_ptr<BaseObject>& replacePtr) {
	m_ptrObject = replacePtr; 
}

BaseOperation* DataHolder::lastOp() {
	if (!m_history.empty())
		return m_history.top(); 
	else return nullptr;
}