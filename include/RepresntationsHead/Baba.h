#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Baba : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Baba(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

	//--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static std::unordered_set<Attribute*>m_babaAttributes;//static attributes for all babas
	std::unordered_set<Attribute*>& getStatic() override;
private:
	static bool m_registerit;
};