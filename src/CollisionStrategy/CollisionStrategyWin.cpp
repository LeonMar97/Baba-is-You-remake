#include "CollisionStrategy/CollisionStrategyWin.h"

CollisionStrategyWin::CollisionStrategyWin()
	: CollisionStrategy(0)
{}

BaseObject* CollisionStrategyWin::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	for (auto& atr : activeObj->getStatic()) {
		if (dynamic_cast<YouWord*>(atr))  //only you can win, dynamic cast is needed
			m_board.endLevel();
	}
	return nullptr; //no more collision detections are needed
}}
