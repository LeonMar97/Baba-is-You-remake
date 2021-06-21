#pragma once
#include "Board.h"
#include <set>
#include"Attribute.h"

class Baba : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Baba(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

	//--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static std::unordered_set<std::shared_ptr<CollisionStrategy>>m_babaAttributes;//static attributes for all babas
	std::set<std::shared_ptr<CollisionStrategy>>& getStatic() override;
private:
	static bool m_registerit;
};