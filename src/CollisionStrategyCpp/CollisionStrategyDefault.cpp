#include "CollisionStrategyDefault.h"

CollisionStrategyDefault::CollisionStrategyDefault()
	: CollisionStrategy(0)
{}

BaseObject* CollisionStrategyDefault::handleCollision(BaseObject*, BaseObject*) {
	return nullptr;
}
