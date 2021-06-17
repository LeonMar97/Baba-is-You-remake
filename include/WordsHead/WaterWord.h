#pragma once
#include "Noun.h" 
#include"Water.h"
class WaterWord :public Noun{
public:
	WaterWord(const sf::Vector2u& loc);
	void replaceObjInLocation(BaseObject*& cur)override;
	std::unordered_set<Attribute*>& getStaticRepresentation() override;
};
