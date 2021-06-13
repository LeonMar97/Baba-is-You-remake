#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Rock : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Rock(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

								  //--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static std::unordered_set<Attribute*>m_rockAtributes;//static attributes for all babas

private:
};
