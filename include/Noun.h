#pragma once
#include "Word.h"
#include "Attribute.h"
#include<unordered_set>
class Noun:public Word {
public:
	using Word::Word;
	virtual std::unordered_set<Attribute&>& getStatic() = 0; //returns spesific static varible which located at each derived class
	virtual  void fillAttributes(Attribute &atr);
	virtual  void removeAttributes();//might be deleted later

};