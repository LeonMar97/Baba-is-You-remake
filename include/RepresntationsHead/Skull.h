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
	static std::unordered_set<Attribute*>m_skullAttributes;//static attributes for all babas
	std::unordered_set<Attribute*>& getStatic() override;

	BaseObject* clone() override { return new Skull(*this); }

private:
};
