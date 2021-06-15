#pragma once
#include "Attribute.h" 
class PushWord :public Attribute{
public:
	PushWord();
	PushWord(const sf::Vector2u& loc);
	bool handleCollision(BaseObject*, BaseObject* obj) override;
};
