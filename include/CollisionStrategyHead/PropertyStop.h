#pragma once
#include "Property.h"

class PropertyStop: public Property {
public:
	PropertyStop();
	BaseObject* handleCollision(BaseObject*, BaseObject*);
};
