#pragma once
#include "Predicate.h"
#include "Noun.h"
class Attribute :public Predicate {
public:
	using Predicate::Predicate;
	void putRuleIntoAffect(Noun&, Board&) override;
	void removeRule(Noun*);
	void deleteRule(Noun&)override;
	//virtual void addRule(Noun&) = 0;
	std::type_index baseTypeId() override;
private:
};