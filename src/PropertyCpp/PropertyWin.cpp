#include "PropertyWin.h"

PropertyWin::PropertyWin(Board& board)
	: Property(0), m_board(board)
{}

BaseObject* PropertyWin::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if (dynamic_cast<PropertyYou*>(atr.get()))  //only you can win, dynamic cast is needed
			m_board.endLevel();
	}
	return nullptr; //no more collision detections are needed
}
