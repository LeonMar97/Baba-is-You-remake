#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Water : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Water(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

								  //--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static std::unordered_set<Attribute*>m_waterAttributes;//static attributes for all babas
	std::unordered_set<Attribute*>& getStatic() override;

private:
};
