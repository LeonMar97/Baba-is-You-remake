#include "RuleHandling.h"

#include "Baba.h"
#include "Is.h"
#include "Rock.h"

void  RuleHandling::processCollision(std::vector<baseObjTuple> &currentTripplesOnBoard ,Board & b)
{
	 std::vector<ruleTuple> currentRules;
	 m_currentTripplesOnBoard = &currentRules;
	for (auto potentialRule : currentTripplesOnBoard) {
		//looks if the current ordered tuple is a rule
		if (auto updateFunPtr = lookup(std::get<0>(potentialRule).baseTypeId(), std::get<1>(potentialRule).baseTypeId(),
			std::get<2>(potentialRule).baseTypeId()))
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
	
	auto ncaRule=ruleTuple(static_cast<Noun&>(std::get<0>(currentRule)),
		static_cast<Conjunction&>(std::get<1>(currentRule)), static_cast<Attribute&>(std::get<2>(currentRule)));
	m_currentTripplesOnBoard->push_back(ncaRule);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//casting function
void RuleHandling::updateRulesNCN(baseObjTuple& currentRule) {
	auto ncnRule = ruleTuple(static_cast<Noun&>(std::get<0>(currentRule)),
		static_cast<Conjunction&>(std::get<1>(currentRule)), static_cast<Noun&>(std::get<2>(currentRule)));
	m_currentTripplesOnBoard->push_back(ncnRule);



}


/// <summary>
/// creating a temporary new rule set and updates the current rule set dynamically
/// </summary>
/// <param name="newRules"></param>

void RuleHandling::updateRules(Board &b) {
	
	bool ruleAlreadyExists = false;
	for (auto ruleIndex = 0; ruleIndex < m_Rules.size(); ruleIndex++) {
		unsigned int amountOfRules = m_currentTripplesOnBoard->size();
		for (unsigned int newRuleIndex = 0; newRuleIndex < amountOfRules; newRuleIndex++) {
			if ((m_Rules[ruleIndex]) == ((*m_currentTripplesOnBoard)[newRuleIndex])) {

				(*m_currentTripplesOnBoard).erase((*m_currentTripplesOnBoard).begin() ); //remove new rule because it already exists
			}
/*

			ruleAlreadyExists = true;
				break;
			}
		}
		if (!ruleAlreadyExists) {
				std::get<2>(m_Rules[ruleIndex]).deleteRule(std::get<0>(m_Rules[ruleIndex]));
				m_Rules.erase(m_Rules.begin() + ruleIndex); //remove old rule because it is no longer on map
			}
		}
	*/
	/*
	for (auto& newRule : newRules) {
		std::get<2>(newRule).putRuleIntoAffect(std::get<0>(newRule), *this);
	}

	*/
		}

	}
}


