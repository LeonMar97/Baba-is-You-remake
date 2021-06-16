
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
typedef std::tuple<std::shared_ptr<Noun>, std::shared_ptr<Conjunction> , std::shared_ptr<Predicate> > ruleTuple;
typedef std::tuple<std::shared_ptr<BaseObject>, std::shared_ptr<BaseObject>, std::shared_ptr<BaseObject>>baseObjTuple;
typedef std::vector<ruleTuple>* ptrToRTVector;
class RuleHandling;
using FunctionPtr = void (RuleHandling::*)(baseObjTuple&);
using Key = std::tuple<std::type_index, std::type_index,std::type_index>;
using RuleToFunctionMap = std::map<Key, FunctionPtr>;

class RuleHandling	{	
	//~~~~~~~~~~~~~~~~ public functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
public:
	
	void processCollision(std::vector<baseObjTuple>& currentTripplesOnBoard, Board& b);

	//~~~~~~~~~~~~~~~~ private members ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
private:
	//Comments A
	//we split them two diffrent vectors because the activation is different in each word, 
		//and polymorphisem wont work without sending extra unusful vars 
	std::vector<ruleTuple>m_RulesInGameNCN;//rules already pluged Noun Conjunction Noun
	std::vector<ruleTuple>m_RulesInGameNCA;//rules already pluged Noun Conjunction Atr
	ptrToRTVector m_AllRulesNCN;//pointer to new Noun Conjunction Noun rules
	ptrToRTVector m_AllRulesNCA;//pointer to new Noun Conjunction Atr rules
	
	//~~~~~~~~~~~~~~~~ private functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void updateRulesNCA(baseObjTuple&);
	void updateRulesNCN(baseObjTuple& currentRule);
	void updateRules(Board& b);
	void updateRulesVector(ptrToRTVector currentRulesOnBoard, ptrToRTVector rules);
	RuleToFunctionMap initializeCollisionMap();
	FunctionPtr lookup(const std::type_index& class1, const std::type_index& class2, const std::type_index& class3);
	void addNewNCA();
	void addNewNCN(Board& b);

};	

