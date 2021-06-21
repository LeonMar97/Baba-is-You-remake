#include "CollisionStrategy/CollisionStrategyDefault.h"

CollisionStrategyDefault::CollisionStrategyDefault()
	: CollisionStrategy(0)
{}

CollisionStrategyDefault::handleCollision(BaseObject*, BaseObject*) {
	return nullptr;
}
