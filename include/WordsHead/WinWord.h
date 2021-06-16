#pragma once
#include "Attribute.h" 
#include "Board.h"
class WinWord :public Attribute{
public:
	WinWord(const sf::Vector2u& loc, Board& m_board);
	bool handleCollision(BaseObject* passiveObj, BaseObject* activeObj)override;
private:
	Board &m_board;
};
