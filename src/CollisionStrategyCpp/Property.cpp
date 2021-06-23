#include "Property.h"


Property::Property(int priority)
	: m_priority(priority)
{}

bool Property::operator<(Property& other) {
	return m_priority < other.m_priority;
}
