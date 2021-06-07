#pragma once
#include "Word.h"
#include "Attribute.h"
#include<unordered_set>
class Noun:public Word {
public:
	using Word::Word;
	virtual  void fillAttributes(Attribute *atr);
	virtual  void removeAttributes();//might be deleted later

};