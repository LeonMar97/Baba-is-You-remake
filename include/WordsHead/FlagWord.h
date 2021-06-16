#pragma once
#include "Noun.h" 
#include"Flag.h"
class FlagWord :public Noun{
public:
	FlagWord(const sf::Vector2u& loc);
	void replaceObjInLocation(BaseObject*& cur)override;
	std::unordered_set<Attribute*>& getStaticRepresentation() override;
};
