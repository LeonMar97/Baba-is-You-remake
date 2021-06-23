#include "PropertyDefault.h"

PropertyDefault::PropertyDefault()
	: Property(0)
{}

BaseObject* PropertyDefault::handleCollision(BaseObject*, BaseObject*) {
	return nullptr;
}
