#pragma once
#include "Attribute.h" 
#include "Board.h"
class SinkWord :public Attribute{
public:
	SinkWord(const sf::Vector2u& loc, Board& board);
	bool handleCollision(BaseObject*, BaseObject* obj) override;
private:
	Board& m_board;
};
