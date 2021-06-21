#pragma once
#include "Noun.h" 
#include"Water.h"
class WaterWord :public Noun{
public:
	WaterWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	CollisionStrategySet & getStaticRepresentation() override;
private:

	static bool m_registerit;
};
