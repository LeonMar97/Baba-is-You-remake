#pragma once
#include "Noun.h" 
#include"Algae.h"
class AlgaeWord :public Noun{
public:
	AlgaeWord(const sf::Vector2u& loc);
	void replaceObjInLocation(std::shared_ptr<BaseObject>& cur, Board& board)override;
	PropertySet& getStaticRepresentation() override;
private:

	static bool m_registerit;
};
