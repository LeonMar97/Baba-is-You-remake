#pragma once
#include "Predicate.h"
#include "Noun.h"
class Attribute :public Predicate {
public:
	using Predicate::Predicate;
	virtual void putRuleIntoAffect(Noun&) ;
	virtual void deleteRule(Noun&)override;
	std::type_index baseTypeId() override;
	virtual bool move(BaseObject& , const Direction& ) { return false; }
private:
};
