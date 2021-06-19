#pragma once
#include "Board.h"
#include "BaseOperation.h"

//a class with a member of direction that represents creating the object
//it is basically the opposite of OperationRemove

template<typename T>
class OperationTransform : public BaseOperation {
public:
	OperationTransform(Board& board) : m_board(board) {}
	void execute(std::shared_ptr<BaseObject>& baseObj) override;
	void undo(std::shared_ptr<BaseObject>& baseObj) override;
private:
	std::shared_ptr<BaseObject> m_previousObject;
	std::shared_ptr<BaseObject> m_currentObject;
	Board& m_board;
};

template<typename T>
void OperationTransform<T>::execute(std::shared_ptr<BaseObject>& baseObj) {
	m_previousObject = baseObj;
	m_board.replaceObjectWith(baseObj, std::make_shared<T>(baseObj->getDir()));
}
template<typename T>
void OperationTransform<T>::undo(std::shared_ptr<BaseObject>& baseObj) {
	m_board.replaceObjectWith(baseObj, m_previousObject);
}
