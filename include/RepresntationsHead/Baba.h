#pragma once
#include "Board.h"
#include <set>
#include"Attribute.h"

class Baba : public BaseObject{
public:
	Baba(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

	static CollisionStrategySet m_babaAttributes;
	CollisionStrategySet& getStatic() override;
private:
	static bool m_registerit;
};