#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Baba : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Baba(const sf::Vector2u& loc);//constractor for static member
	//--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static std::unordered_set<Attribute*>m_babaAtributes;//static attributes for all babas


private:
};