#include "PropertyDefeat.h"

PropertyDefeat::PropertyDefeat(Board& board)
	: Property(0), m_board(board)
{
	m_defeatSound.setBuffer(Resources::instance().get_Sounds(defeatSound_t));
	m_defeatSound.setVolume(30);
}

BaseObject* PropertyDefeat::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& proprty: activeObj->getStatic()) {
		if (dynamic_cast<PropertyYou*>(proprty.get())) {
			activeObj->executeOperation(new OperationRemove(m_board));
			m_defeatSound.play();
		}
	}
	return nullptr;
}
