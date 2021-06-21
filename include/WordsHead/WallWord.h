#pragma once
#include "Noun.h" 
#include"Wall.h"
class WallWord :public Noun{
public:
	WallWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	CollisionStrategySet & getStaticRepresentation() override;
private:

	static bool m_registerit;
};
