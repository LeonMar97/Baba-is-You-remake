#pragma once
#include "Property.h"
#include "OperationsHead/OperationMove.h"

class PropertyYou : public Property {
public:
	PropertyYou();
	BaseObject* handleCollision(BaseObject*, BaseObject*);
	bool move(BaseObject& curYou, const Direction& dir) override;
private:
	sf::Sound m_movementSound;
};
