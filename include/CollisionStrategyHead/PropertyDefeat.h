#pragma once
#include "Property.h"
#include "OperationRemove.h"
#include "PropertyYou.h"

class PropertyDefeat: public Property {
public:
	PropertyDefeat(Board& board);
	BaseObject* handleCollision(BaseObject*, BaseObject*) override ;
private:
	Board& m_board;
};
