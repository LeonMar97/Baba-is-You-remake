#pragma once
#include "Attribute.h" 
class YouWord :public Attribute{
public:
	YouWord(const sf::Vector2u& loc);
	 bool move(BaseObject& curYou, const Direction& dir)override ;
	 

};
