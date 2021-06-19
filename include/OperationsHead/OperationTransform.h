#pragma once
#include "Board.h"
#include "BaseOperation.h"

//a class with a member of direction that represents creating the object
//it is basically the opposite of OperationRemove

template<typename T>
class OperationTransform : public BaseOperation {
public:
	void execute(const std::shared_ptr<BaseObject>& baseObj) override;
	void undo(const std::shared_ptr<BaseObject>& baseObj) override;
private:
	BaseObject* m_previousObject;
};

template<typename T>
void OperationTransform<T>::execute(const std::shared_ptr<BaseObject>& baseObj) {
	m_previousObject = baseObj;
	*baseObj = T(baseObj->castToLoc(baseObj->returnPos()));
}

template<typename T>
void OperationTransform<T>::undo(const std::shared_ptr<BaseObject>& baseObj) {
	//*baseObj = *m_previousObject;
}
