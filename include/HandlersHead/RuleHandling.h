
#pragma once
#include "Noun.h"
#include "Attribute.h"
#include "Conjunction.h"
#include <map>
#include <typeinfo>
#include <typeindex>
#include <iostream>
#include<tuple>
#include "Macros.h"
typedef std::tuple<Noun&, Conjunction&, Predicate&>ruleTuple;
typedef std::tuple<BaseObject&, BaseObject&, BaseObject&>baseObjTuple;

using FunctionPtr = void (RuleHandling::*)(baseObjTuple&);
using Key = std::tuple<std::type_index, std::type_index,std::type_index>;
using RuleToFunctionMap = std::map<Key, FunctionPtr>;

class RuleHandling	{	
	
public:
	
	void processCollision(baseObjTuple&);
	
private:
	std::vector<ruleTuple>m_Rules;
	void updateRulesNCA(baseObjTuple&);
	void updateRulesNCN(baseObjTuple& currentRule);

	void updateRules(ruleTuple&);
	
	RuleToFunctionMap initializeCollisionMap();
	FunctionPtr lookup(const std::type_index& class1, const std::type_index& class2, const std::type_index& class3);

};	

