#pragma once
#include "Property.h"
#include "OperationsHead/OperationRemove.h"

class PropertySink: public Property {
public:
	PropertySink(Board& board);
	BaseObject* handleCollision(BaseObject*, BaseObject*);
private:
	Board& m_board;
	sf::Sound m_drownSound;
};
