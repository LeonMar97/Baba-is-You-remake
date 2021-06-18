#pragma once
#include <Memory>
#include "BaseDataHolder.h"
#include "BaseOperation.h"
#include "BaseObject.h"
#include <stack>
template<typename T>
class DataHolder : public BaseDataHolder{
public:
	DataHolder(std::unique_ptr<T>&& baseObj) : m_ptrObject(std::move(baseObj)) {}
	BaseObject* getPtr() { return static_cast<BaseObject*>(m_ptrObject); }
	//T* operator->() const { return m_ptrObject->get(); }
private:
	const std::unique_ptr<T> m_ptrObject;
};
