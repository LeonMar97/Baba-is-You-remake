#pragma once
#include "Conjunction.h" 
class Is :public Conjunction{
public:
	Is(const sf::Vector2u& loc);
private:

	static bool m_registerit;
};