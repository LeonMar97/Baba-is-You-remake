#pragma once
#include "Attribute.h" 
#include "CollisionStrategy/CollisionStrategyPush.h"
class PushWord :public Attribute{
public:
	PushWord();
	PushWord(const sf::Vector2u& loc);
	//bool handleCollision(BaseObject*, BaseObject* obj) override;
private:

	static bool m_registerit;
};
