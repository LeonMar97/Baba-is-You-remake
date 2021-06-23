#include "Property.h"


Property::Property(int priority)
	: m_priority(priority)
{}

//most attributes do not handle move, so there is no point making it abstract
bool Property::move(BaseObject& , const Direction& ) {
	return false; //a movement did not occur
}

bool Property::operator<(Property& other) {
	return m_priority < other.m_priority;
}
