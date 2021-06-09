#pragma once
#include "Word.h"
#include "Noun.h"
class Attribute :public Word {
public:
	using Word::Word;
	void putRuleIntoAffect(Noun&, Board&) override;
private:
};