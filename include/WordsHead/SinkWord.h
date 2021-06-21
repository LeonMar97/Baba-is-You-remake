#pragma once
#include "Attribute.h" 
#include "Board.h"
#include "CollisionStrategySink.h"
class SinkWord :public Attribute{
public:
	SinkWord(const sf::Vector2u& loc, Board& board);
	//bool handleCollision(BaseObject*, BaseObject* obj) override;
private:
	static bool m_registerit;
};
