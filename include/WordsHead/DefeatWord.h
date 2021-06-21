#pragma once
#include "Attribute.h" 
#include "Board.h";
#include "OperationRemove.h"
#include "CollisionStrategyDefeat.h"
class DefeatWord :public Attribute{
public:
	DefeatWord(const sf::Vector2u& loc, Board& board);
	//bool handleCollision(BaseObject*, BaseObject* obj) override;
private:
	static bool m_registerit;
};
