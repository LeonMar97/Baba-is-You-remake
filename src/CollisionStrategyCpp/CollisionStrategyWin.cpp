#include "CollisionStrategyWin.h"

CollisionStrategyWin::CollisionStrategyWin(Board& board)
	: CollisionStrategy(0), m_board(board)
{}

BaseObject* CollisionStrategyWin::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if (dynamic_cast<CollisionStrategyYou*>(atr.get()))  //only you can win, dynamic cast is needed
			m_board.endLevel();
	}
	return nullptr; //no more collision detections are needed
}
