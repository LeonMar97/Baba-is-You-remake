#pragma once
#include "Noun.h" 
#include"Baba.h"
class BabaWord :public Noun{
public:
	BabaWord(const sf::Vector2u& loc);
	PropertySet & getStaticRepresentation() override;
	///PropertySet& getStatic() override;
	void replaceObjInLocation(std::shared_ptr<BaseObject>&, Board& board) override;
private:

	static bool m_registerit;
};
