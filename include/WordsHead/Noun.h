#pragma once
#include "Predicate.h"
#include "Attribute.h"
#include<unordered_set>
class Board;
class Noun:public Predicate {
public:
	//NEED TO CHECK IF NEED GameObjects id
	Noun(const std::string& word, const AnimationData& animationData,
		Direction dir, const sf::Vector2u& loc,
		char objectCreationChar, GameObjects objectCreationCharEnum);
	Noun(const std::string& word, const AnimationData& animationData,
		Direction dir, const sf::Vector2u& loc, const sf::Color& color,
		char objectCreationChar, GameObjects objectCreationCharEnum);
	virtual  void fillAttributes(Attribute *atr);
	virtual  void removeAttribute(Attribute*);//might be deleted later
	void putRuleIntoAffect(Noun&, Board&) ;
	//rule removing doesnt effect the noun but needed empty for polymorphic 
		//prefrences when attribte thus created in class predicate virtually 
	void deleteRule(Noun&) {};
	//getting a location in the board for which a new representaion of the current noun will be created instead of it.
	virtual  void replaceObjInLocation(BaseObject*&)=0;

	virtual std::unordered_set<Attribute*>& getStatic() = 0;
	virtual std::unordered_set<Attribute*>& getStaticRepresentation() = 0;
	std::type_index baseTypeId()override;
private:
	char m_objectCreationChar;
	GameObjects m_objectCreationEnum;
};