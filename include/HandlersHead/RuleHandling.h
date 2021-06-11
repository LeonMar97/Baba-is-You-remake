#pragma once
#include "Noun.h"
#include "Attribute.h"
#include "Conjunction.h"
#include <map>
#include <typeinfo>
#include <typeindex>
#include <iostream>

using FunctionPtr = void (*)(BaseObject&, BaseObject&, BaseObject&);
using Key = std::tuple<std::type_index, std::type_index,std::type_index>;
using RuleToFunctionMap = std::map<Key, FunctionPtr>;

class RuleHandling	{	
	
public:
	
	void processCollision(BaseObject& object1, BaseObject& object2,BaseObject& object3);
	
private:
	RuleToFunctionMap initializeCollisionMap();
	FunctionPtr lookup(const std::type_index& class1, const std::type_index& class2, const std::type_index& class3);

};	
