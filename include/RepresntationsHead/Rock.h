#pragma once
#include "Board.h"
#include <set>
#include"Attribute.h"

class Rock : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Rock(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

								  //--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static CollisionStrategySet m_rockAttributes;
	CollisionStrategySet & getStatic() override;

private:
	static bool m_registerit;
};
