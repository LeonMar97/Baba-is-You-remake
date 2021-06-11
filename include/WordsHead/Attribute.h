#pragma once
#include "Predicate.h"
#include "Noun.h"
class Attribute :public Predicate {
public:
	using Predicate::Predicate;
	void putRuleIntoAffect(Noun&, Board&) override;
	void removeRule(Noun*);

	const std::type_index& baseTypeId() override;
private:
};