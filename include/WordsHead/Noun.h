#pragma once
#include "Predicate.h"
#include "Attribute.h"
#include<unordered_set>
class Board;
class Noun:public Predicate {
public:
	//NEED TO CHECK IF NEED GameObjects id
	Noun(const std::string& word, const AnimationData& animationData,
		Direction dir, const sf::Vector2u& loc, const sf::Color& color, const sf::Color&);
	virtual  void fillAttributes(std::shared_ptr<Property>&);
	virtual  void removeAttribute(std::shared_ptr<Property>&);//might be deleted later
	void putRuleIntoAffect(Noun&, Board&) ;
	//rule removing doesnt effect the noun but needed empty for polymorphic 
		//prefrences when attribte thus created in class predicate virtually 
	void deleteRule(Noun&) {};
	//getting a location in the board for which a new representaion of the current noun will be created instead of it.
	virtual void replaceObjInLocation(std::shared_ptr<BaseObject>&, Board&)=0;

	virtual PropertySet& getStaticRepresentation() = 0;
	std::type_index baseTypeId()override;
private:
};