#pragma once
#include "Attribute.h" 
class StopWord :public Attribute{
public:
	StopWord();
	StopWord(const sf::Vector2u& loc);
	bool handleCollision(BaseObject*, BaseObject* obj) override;
};