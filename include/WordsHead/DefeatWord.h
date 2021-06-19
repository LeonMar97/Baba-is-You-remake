#pragma once
#include "Attribute.h" 
#include "Board.h";
class DefeatWord :public Attribute{
public:
	DefeatWord(const sf::Vector2u& loc, Board& board);
	bool handleCollision(BaseObject*, BaseObject* obj) override;
private:
	Board& m_board;
};