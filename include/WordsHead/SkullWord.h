#pragma once
#include "Noun.h" 
#include"Skull.h"
class SkullWord :public Noun{
public:
	SkullWord(const sf::Vector2u& loc);
	void replaceObjInLocation(BaseObject*& cur)override;
	std::unordered_set<Attribute*>& getStaticRepresentation() override;
};
