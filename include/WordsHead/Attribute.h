#pragma once
#include "Predicate.h"
#include "Noun.h"
class Attribute :public Predicate {
public:
	using Predicate::Predicate;
	void putRuleIntoAffect(Noun&) ;
	void removeRule(Noun*);
	void deleteRule(Noun&)override;
	std::type_index baseTypeId() override;
private:
};