#pragma once
#include "Noun.h" 
#include"Wall.h"
class WallWord :public Noun{
public:
	WallWord(const sf::Vector2u& loc);
	void replaceObjInLocation(BaseObject*& cur)override;
	std::unordered_set<Attribute*>& getStaticRepresentation() override;
};
