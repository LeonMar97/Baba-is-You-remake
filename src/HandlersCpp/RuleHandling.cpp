#include "RuleHandling.h"


void  RuleHandling::processCollision(BaseObject& object1, BaseObject& object2, BaseObject& object3)
{
    if (auto phf = lookup(typeid(object1), typeid(object2), typeid(object3)))
    {
        //the current tuple is a rule 

    }
    //else it does nothing because the current rule 

}


RuleToFunctionMap RuleHandling:: initializeCollisionMap(){
    RuleToFunctionMap map;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Attribute) )] = &updateRules;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Noun)      )] = &updateRules;
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


void Board::replace(GameObjects objectToAdd, GameObjects objectToRemove, char objectToCreate) {
	for (auto& removeObj : m_dataHolder[objectToRemove]) {
		auto removeObjPos = removeObj->returnPos() / OBJECT_SIZE;
		addGameObj(objectToCreate, sf::Vector2u(removeObjPos.y, removeObjPos.x));
		delete removeObj;
	}
	m_dataHolder[objectToRemove].clear();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//



/// <summary>
/// creating a temporary new rule set and updates the current rule set dynamically
/// </summary>
/// <param name="newRules"></param>
void Board::updateRules(std::vector<ruleTuple>& newRules) {
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


