#pragma once
#include "Word.h"
class Predicate:public Word
{
public:
	using Word::Word;
	virtual void deleteRule(Noun &)=0;
	//virtual void addRule(Noun&) = 0;

private:

};
