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
	static PropertySet m_waterAttributes;
	PropertySet & getStatic() override;

private:
	static bool m_registerit;
};
