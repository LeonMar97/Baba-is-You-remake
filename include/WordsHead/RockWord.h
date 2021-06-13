#pragma once
#include "Noun.h" 
#include"Rock.h"
class RockWord :public Noun{
public:
	RockWord(const sf::Vector2u& loc);
	std::unordered_set<Attribute*>& getStatic()override;
	void replaceObjInLocation(BaseObject*& cur)override;


};
