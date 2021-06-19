#include "OperationMove.h"

OperationMove::OperationMove(Direction dir)
	: m_dir(dir)
{}
void OperationMove::execute(const std::shared_ptr<BaseObject>& baseObj) {
	baseObj->move(m_dir);
}
void OperationMove::undo(const std::shared_ptr<BaseObject>& baseObj) {
	baseObj->move(opposite(m_dir)); 
}
