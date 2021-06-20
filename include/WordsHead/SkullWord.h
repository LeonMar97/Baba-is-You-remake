#pragma once
#include "Noun.h" 
#include"Skull.h"
class SkullWord :public Noun{
public:
	SkullWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	std::unordered_set<Attribute*>& getStaticRepresentation() override;
private:
	static bool m_registerit;
};
