#pragma once
#include "Attribute.h" 
#include "PushWord.h"
#include "CollisionStrategyYou.h"
class YouWord :public Attribute{
public:
	YouWord(const sf::Vector2u& loc);
	 //bool move(BaseObject& curYou, const Direction& dir)override ;
	 
private:
	static bool m_registerit;
};
