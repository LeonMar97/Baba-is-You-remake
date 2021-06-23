#pragma once
#include "Property.h"
#include "WordsHead/YouWord.h"
#include "Board.h"

class PropertyWin: public Property {
public:
	PropertyWin(Board& board);
	BaseObject* handleCollision(BaseObject*, BaseObject*);
private:
	Board& m_board;
};
