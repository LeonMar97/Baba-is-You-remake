#pragma once
#include "Attribute.h" 
#include "PushWord.h"
class YouWord :public Attribute{
public:
	YouWord(const sf::Vector2u& loc);
	 bool move(BaseObject& curYou, const Direction& dir)override ;
	 
	void putRuleIntoAffect(Noun&)override ;
	void deleteRule(Noun&)override;
private:
	PushWord m_pushOfYou;
	static bool m_registerit;
};
