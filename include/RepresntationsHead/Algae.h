#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Algae : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Algae(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

	//------------------members-----------------------------------//
	static PropertySet m_algaeAttributes;
	PropertySet& getStatic() override;
private:
	static bool m_registerit;
};
