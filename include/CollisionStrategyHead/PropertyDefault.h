#pragma once
#include "Property.h"

class PropertyDefault : public Property {
public:
	PropertyDefault();
	BaseObject* handleCollision(BaseObject*, BaseObject*);
};