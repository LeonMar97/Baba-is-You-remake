#pragma once
#include "Word.h"
#include "Attribute.h"
#include<unordered_set>
class Board;
class Noun:public Word {
public:
	//NEED TO CHECK IF NEED GameObjects id
	Noun(const std::string& word, const AnimationData& animationData,
		Direction dir, const sf::Vector2u& loc,
		char objectCreationChar, GameObjects objectCreationCharEnum);
	virtual  void fillAttributes(Attribute *atr);
	virtual  void removeAttributes(Attribute*);//might be deleted later
	void putRuleIntoAffect(Noun&, Board&) override;
private:
	char m_objectCreationChar;
	GameObjects m_objectCreationEnum;
};