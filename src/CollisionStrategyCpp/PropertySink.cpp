#include "PropertySink.h"
PropertySink::PropertySink(Board& board)
	: Property(1), m_board(board)
{
	m_drownSound.setBuffer(Resources::instance().get_Sounds(drown_t));
	m_drownSound.setVolume(30);
}

BaseObject* PropertySink::handleCollision(BaseObject * passiveObj, BaseObject * activeObj) {
	//activeObj->undoOperation(); //for active object positioning after redo
	//remove both objects from board using operationRemove
	activeObj->executeOperation(new OperationRemove(m_board));
	passiveObj->executeOperation(new OperationRemove(m_board));
	m_drownSound.play();
	return nullptr;
}
