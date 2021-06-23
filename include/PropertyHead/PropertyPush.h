#pragma once
#include "Property.h"
#include "OperationsHead/OperationMove.h"

class PropertyPush: public Property {
public:
	PropertyPush();
	BaseObject* handleCollision(BaseObject*, BaseObject*);
};
