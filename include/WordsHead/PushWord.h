#pragma once
#include "Attribute.h" 
class PushWord :public Attribute{
public:
	PushWord(const sf::Vector2u& loc);
	void handleCollision(BaseObject*, BaseObject* obj) override;
};
