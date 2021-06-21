#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Skull : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Skull(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

								  //--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static CollisionStrategySet m_skullAttributes;

	CollisionStrategySet & getStatic() override;

private:
	static bool m_registerit;
};
