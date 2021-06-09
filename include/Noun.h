#pragma once
#include "Word.h"
#include "Attribute.h"
#include<unordered_set>
class Noun:public Word {
public:
	using Word::Word;
	virtual  void fillAttributes(Attribute *atr);
	virtual  void removeAttributes(Attribute*);//might be deleted later
	void putRuleIntoAffect(Noun&, Board&) override;


};