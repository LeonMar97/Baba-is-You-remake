#pragma once
#include "Board.h"
#include <set>
#include"Attribute.h"

class Baba : public BaseObject{
public:
	Baba(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

	static PropertySet m_babaAttributes;
	PropertySet& getStatic() override;
private:
	static bool m_registerit;
};