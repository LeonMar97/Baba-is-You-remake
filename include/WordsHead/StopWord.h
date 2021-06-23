#pragma once
#include "Attribute.h" 
#include "NoOperation.h"
#include "PropertyStop.h"
class StopWord :public Attribute{
public:
	StopWord(const sf::Vector2u& loc);
	//bool handleCollision(BaseObject*, BaseObject* obj) override;
private:
	static bool m_registerit;
};
