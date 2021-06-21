#pragma once
#include "Noun.h" 
#include"Rock.h"
#include "OperationTransform.h"
class RockWord :public Noun{
public:
	RockWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	std::set<std::shared_ptr<CollisionStrategy>> & getRepresentationStatic() override;
private:
	static bool m_registerit;
};
