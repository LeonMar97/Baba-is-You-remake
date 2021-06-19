#pragma once
#include "Noun.h" 
#include"Baba.h"
class BabaWord :public Noun{
public:
	BabaWord(const sf::Vector2u& loc);
	std::unordered_set<Attribute*>& getStaticRepresentation() override;
	///std::unordered_set<Attribute*>& getStatic() override;
	void replaceObjInLocation(std::shared_ptr<BaseObject>&, Board& board) override;
};
