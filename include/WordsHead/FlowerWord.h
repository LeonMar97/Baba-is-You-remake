
#pragma once
#include "Noun.h" 
#include"Flower.h"
class FlowerWord :public Noun{
public:
	FlowerWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	CollisionStrategySet& getStaticRepresentation() override;
private:

	static bool m_registerit;
};
