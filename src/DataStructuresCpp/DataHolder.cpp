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
		auto op = m_history.top(); 
		m_history.pop();
		op->undo(m_ptrObject);
		delete op;
		return true;
	}
	return false;
}

void DataHolder::replacePtr(const std::shared_ptr<BaseObject>& replacePtr) {
	m_ptrObject = replacePtr; 
}

//retuens last operation
BaseOperation* DataHolder::lastOp() {
	if (!m_history.empty())
		return m_history.top(); 
	else return nullptr;
}

DataHolder::~DataHolder(){
	m_ptrObject->resetStatic();

}
void DataHolder::lruRestart() {
	m_ptrObject->lruRestart();
}
