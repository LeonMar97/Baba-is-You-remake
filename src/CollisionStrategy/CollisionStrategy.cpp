#include "CollisionStrategy/CollisionStrategy.h"

CollisionStrategy::CollisionStrategy(int priority)
	: m_priority(priority)
{}

bool CollisionStrategy::operator<(CollisionStrategy& other) {
	return m_priority < other.m_priority;
}