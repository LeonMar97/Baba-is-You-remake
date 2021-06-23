#pragma once
#include "Noun.h" 
#include"Rock.h"
#include "OperationTransform.h"
class RockWord :public Noun{
public:
	RockWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	PropertySet& getStaticRepresentation() override;
private:
	static bool m_registerit;
};
