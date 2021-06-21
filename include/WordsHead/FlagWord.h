#pragma once
#include "Noun.h" 
#include"Flag.h"
class FlagWord :public Noun{
public:
	FlagWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	CollisionStrategySet& getStaticRepresentation() override;
private:

	static bool m_registerit;
};
