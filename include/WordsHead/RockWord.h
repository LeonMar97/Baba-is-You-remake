#pragma once
#include "Noun.h" 
#include"Rock.h"
class RockWord :public Noun{
public:
	RockWord(const sf::Vector2u& loc);
	void replaceObjInLocation(BaseObject*& cur)override;
	std::unordered_set<Attribute*>& getStaticRepresentation() override;
	std::unordered_set<Attribute*>& getStatic() override;
};
