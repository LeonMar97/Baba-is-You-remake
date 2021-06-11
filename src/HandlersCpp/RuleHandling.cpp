#include "RuleHandling.h"


void  RuleHandling::processCollision(baseObjTuple& potentialRule)
{
    if (auto updateFunPtr = lookup(typeid(std::get<0>(potentialRule)), typeid(std::get<1>(potentialRule)),
		typeid(std::get<2>(potentialRule))))
    {
        //the current tuple is a rule 
		updateFunPtr(potentialRule);

    }
    //else it does nothing because the current rule 

}


RuleToFunctionMap RuleHandling:: initializeCollisionMap(){
    RuleToFunctionMap map;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Attribute) )] = &updateRulesNCA;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Noun)      )] = &updateRulesNCN;
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
	
	auto ncaRule=ruleTuple(static_cast<Noun&>(std::get<0>(currentRule)),
		static_cast<Conjunction&>(std::get<1>(currentRule)), static_cast<Attribute&>(std::get<2>(currentRule)));
	 updateRules(ncaRule);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//casting function
void RuleHandling::updateRulesNCN(baseObjTuple& currentRule) {
	auto ncnRule = ruleTuple(static_cast<Noun&>(std::get<0>(currentRule)),
		static_cast<Conjunction&>(std::get<1>(currentRule)), static_cast<Noun&>(std::get<2>(currentRule)));
	updateRules(ncnRule);

}


/// <summary>
/// creating a temporary new rule set and updates the current rule set dynamically
/// </summary>
/// <param name="newRules"></param>
void RuleHandling::updateRules(ruleTuple&) {
	bool ruleAlreadyExists = false;
	for (auto ruleIndex = 0; ruleIndex < m_Rules.size(); ruleIndex++) {
		for (auto newRuleIndex = 0; newRuleIndex < newRules.size(); newRuleIndex++) {
			if (m_Rules[ruleIndex] == newRules[newRuleIndex]) {
				newRules.erase(newRules.begin() + newRuleIndex); //remove new rule because it already exists
				ruleAlreadyExists = true;
				break;
			}
		}
		if (!ruleAlreadyExists) {
			if (auto atrPtr = dynamic_cast<Attribute*>(&(std::get<2>(m_Rules[ruleIndex])))) {
				std::get<0>(m_Rules[ruleIndex]).removeAttributes(atrPtr);
				m_Rules.erase(m_Rules.begin() + ruleIndex); //remove old rule because it is no longer on map
			}
		}
	}
	for (auto& newRule : newRules) {
		std::get<2>(newRule).putRuleIntoAffect(std::get<0>(newRule), *this);
	}
}


