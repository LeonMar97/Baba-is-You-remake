#include "RuleHandling.h"
#include "WinWord.h"

RuleHandling::RuleHandling()
{
	m_ruleDetectionSound.setBuffer(Resources::instance().get_Sounds(ruleDetection_t));
	m_ruleDetectionSound.setVolume(30);
	m_ruleRemoveSound.setBuffer(Resources::instance().get_Sounds(ruleRemove_t));
	m_ruleRemoveSound.setVolume(30);
}

void  RuleHandling::processCollision(std::vector<baseObjTuple> &currentTriplesOnBoard ,Board & b)
{
	 std::vector<ruleTuple> currentRulesNCN;
	 std::vector<ruleTuple> currentRulesNCA;

	 m_AllRulesNCA = &currentRulesNCA;
	 m_AllRulesNCN = &currentRulesNCN;

	for (auto &potentialRule : currentTriplesOnBoard) {

		auto& [first, second, third] = potentialRule;
		//first checking whether  'you' 'is' 'win' which stops the game and making the rule seeking void..
		if (auto updateFunPtr = lookup(typeid(*first),
			typeid(*second),typeid(*third))) {

			(this->*updateFunPtr)(potentialRule);
			break;
		}
		//looks if the current ordered tuple is a rule
		if (auto updateFunPtr = lookup(first->baseTypeId(), second->baseTypeId(),
			third->baseTypeId()))
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
	map[Key(typeid(YouWord), typeid(Is), typeid(WinWord))] = &RuleHandling::youWin;
	


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
	
	auto& [noun, con, atr] = currentRule;
	auto ncaRule=ruleTuple(
		static_cast<Noun*>(noun),
		static_cast<Conjunction*>(con),
		static_cast<Attribute*>(atr));
	m_AllRulesNCA->push_back(ncaRule);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//casting function
void RuleHandling::updateRulesNCN(baseObjTuple& currentRule) {
	auto& [noun1, con, noun2] = currentRule;
	auto ncnRule = ruleTuple(
		static_cast<Noun*>(noun1),
		static_cast<Conjunction*>(con),
		static_cast<Noun*>(noun2));
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
void RuleHandling::updateRulesVector(ptrToRTVector currentRulesOnBoard, ptrToRTVector rules) {
	bool ruleAlreadyExists = false;
	for(auto rule_it = rules->begin(); rule_it < rules->end();){
		ruleAlreadyExists = false;
		for(auto ruleOnBoard_it = currentRulesOnBoard->begin(); ruleOnBoard_it < currentRulesOnBoard->end();){
			if (*rule_it == *ruleOnBoard_it) {
				ruleOnBoard_it = currentRulesOnBoard->erase(ruleOnBoard_it); //remove new rule because it already exists
				ruleAlreadyExists = true;
				break;
			}
			else ruleOnBoard_it++;
		}
		if (!ruleAlreadyExists) {
			auto& [noun, con, pred] = (*rule_it);
			noun->setDefaultColor();
			con->setDefaultColor();
			pred->setDefaultColor();
			pred->deleteRule(*noun);
			m_ruleRemoveSound.play();
			rule_it = rules->erase(rule_it); //remove old rule because it is no longer on map
		}
		else rule_it++;
	}
}

void RuleHandling::addNewNCA() {
	//triggering new attributes and inserting the current new rule in his vector 
	for (auto& ruleToAdd : *m_AllRulesNCA) {
		auto &[noun, con, pred] = ruleToAdd;
		static_cast<Attribute*>(pred)->putRuleIntoAffect(*noun);
		m_RulesInGameNCA.push_back(ruleToAdd);
		noun->setLighterColor();
		con->setLighterColor();
		pred->setLighterColor();

		m_ruleDetectionSound.play();
	}
	m_AllRulesNCA = nullptr;//not neccesery but to state a point ..
}

void RuleHandling::addNewNCN(Board &b) {
	for (auto& ruleToAdd : *m_AllRulesNCN) {//for each rule
		auto &[noun, con, pred] = ruleToAdd;
		b.replaceObjects(*noun,*static_cast<Noun*>(pred));
		m_RulesInGameNCN.push_back(ruleToAdd);
		noun->setLighterColor();
		con->setLighterColor();
		pred->setLighterColor();
		m_ruleDetectionSound.play();
	}
	m_AllRulesNCN = nullptr;//not neccesery but to state a point ..
}

void RuleHandling::youWin(baseObjTuple& currentRule) {
	auto& [noun, con, pred] = currentRule;
	
	static_cast<WinWord*>(pred)->youWin();

}
