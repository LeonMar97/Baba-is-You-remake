#include "RuleHandling.h"

#include "Baba.h"
#include "Is.h"
#include "Rock.h"

void  RuleHandling::processCollision(std::vector<baseObjTuple> &currentTripplesOnBoard ,Board & b)
{
	 std::vector<ruleTuple> currentRulesNCN;
	 std::vector<ruleTuple> currentRulesNCA;

	 m_AllRulesNCA = &currentRulesNCA;
	 m_AllRulesNCN = &currentRulesNCN;

	for (auto &potentialRule : currentTripplesOnBoard) {
		//looks if the current ordered tuple is a rule
		if (auto updateFunPtr = lookup(std::get<0>(potentialRule)->baseTypeId(), std::get<1>(potentialRule)->baseTypeId(),
			std::get<2>(potentialRule)->baseTypeId()))
		{
			//the current tuple is a rule 
			(this->*updateFunPtr)(potentialRule);

		}
	}
	updateRules(b);
    
}



RuleToFunctionMap RuleHandling:: initializeCollisionMap(){
    RuleToFunctionMap map;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Attribute) )] = &RuleHandling::updateRulesNCA;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Noun)      )] = &RuleHandling::updateRulesNCN;
    return map;
}

FunctionPtr RuleHandling::lookup(const std::type_index& class1, const std::type_index& class2, const std::type_index& class3) {
    static RuleToFunctionMap ruleMap = initializeCollisionMap();
    auto mapEntry = ruleMap.find(std::make_tuple(class1, class2,class3));
    if (mapEntry == ruleMap.end()){
        return nullptr;
    }
    return mapEntry->second;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//casting function
void RuleHandling::updateRulesNCA(baseObjTuple& currentRule) {
	
	auto ncaRule=ruleTuple(static_cast<Noun*>(std::get<0>(currentRule)),
		static_cast<Conjunction*>(std::get<1>(currentRule)), static_cast<Attribute*>(std::get<2>(currentRule)));
	m_AllRulesNCA->push_back(ncaRule);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//casting function
void RuleHandling::updateRulesNCN(baseObjTuple& currentRule) {
	auto ncnRule = ruleTuple(static_cast<Noun*>(std::get<0>(currentRule)),
		static_cast<Conjunction*>(std::get<1>(currentRule)), static_cast<Noun*>(std::get<2>(currentRule)));
	m_AllRulesNCN->push_back(ncnRule);
}


/// <summary>
/// creating a temporary new rule set and updates the current rule set dynamically
/// </summary>
/// <param name="newRules"></param>

void RuleHandling::updateRules(Board &b) {
	
	updateRulesVector(m_AllRulesNCN, &m_RulesInGameNCN);
	updateRulesVector(m_AllRulesNCA, &m_RulesInGameNCA);
	addNewNCN(b);
	addNewNCA();

	
}
/// <summary>
/// loops on the current rule vector and removes unnesesery rules to add and deactivates broken rules 
/// </summary>
/// <param name="currentRulesOnBoard"></param>
/// <param name="rules"></param>
void RuleHandling::updateRulesVector(ptrToRTVector currentRulesOnBoard, ptrToRTVector rules ) {
	bool ruleAlreadyExists = false;
	for (auto ruleIndex = 0; ruleIndex < rules->size(); ruleIndex++) {
		ruleAlreadyExists = false;
		unsigned int amountOfRules = currentRulesOnBoard->size();
		for (unsigned int newRuleIndex = 0; newRuleIndex < currentRulesOnBoard->size(); newRuleIndex++) {
		if (((*rules)[ruleIndex]) == ((*currentRulesOnBoard)[newRuleIndex])) {
				(currentRulesOnBoard)->erase(currentRulesOnBoard->begin() + newRuleIndex); //remove new rule because it already exists
				ruleAlreadyExists = true;
				break;
			}
		}
		if (!ruleAlreadyExists) {
			(std::get<2>((*rules)[ruleIndex]))->deleteRule(*(std::get<0>((*rules)[ruleIndex])));
			rules->erase(rules->begin() + ruleIndex); //remove old rule because it is no longer on map
		}
	}
}

void RuleHandling::addNewNCA() {
	//triggering new attributes and inserting the current new rule in his vector 
	for (auto& ruleToAdd : *m_AllRulesNCA) {
		static_cast<Attribute*>(std::get<2>(ruleToAdd))->putRuleIntoAffect(*std::get<0>(ruleToAdd));
		m_RulesInGameNCA.push_back(ruleToAdd);
	}
	m_AllRulesNCA = nullptr;//not neccesery but to state a point ..
}

void RuleHandling::addNewNCN(Board &b) {
	for (auto& ruleToAdd : *m_AllRulesNCN) {//for each rule
		b.replaceObjects(*std::get<0>(ruleToAdd),*static_cast<Noun*>(std::get<2>(ruleToAdd)));
		m_RulesInGameNCN.push_back(ruleToAdd);
	}
	m_AllRulesNCN = nullptr;//not neccesery but to state a point ..
}

