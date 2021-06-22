#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Flower : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Flower(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

	//------------------members-----------------------------------//
	static CollisionStrategySet m_flowerAttributes;
	CollisionStrategySet& getStatic() override;
private:
	static bool m_registerit;
};
