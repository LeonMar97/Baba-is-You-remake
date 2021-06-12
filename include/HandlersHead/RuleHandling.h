
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
class RuleHandling;
using FunctionPtr = void (RuleHandling::*)(baseObjTuple&);
using Key = std::tuple<std::type_index, std::type_index,std::type_index>;
using RuleToFunctionMap = std::map<Key, FunctionPtr>;

class RuleHandling	{	
	
public:
	
	void processCollision(std::vector<baseObjTuple>& currentTripplesOnBoard, Board& b);
	
private:
	std::vector<ruleTuple>m_Rules;
	void updateRulesNCA(baseObjTuple&);
	void updateRulesNCN(baseObjTuple& currentRule);

	void updateRules(Board& b);
	std::vector<ruleTuple>*m_currentTripplesOnBoard;
	RuleToFunctionMap initializeCollisionMap();
	FunctionPtr lookup(const std::type_index& class1, const std::type_index& class2, const std::type_index& class3);

};	

