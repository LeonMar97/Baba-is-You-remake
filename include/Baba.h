#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Baba : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Baba(const sf::Vector2u& loc);//constractor for static member
	//void draw(sf::RenderWindow& window, float deltaTime);
	bool move(Board* board, BaseObject*, const sf::Vector2i&);
	bool onMove(Board* board, const sf::Vector2i&);
	//--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static std::unordered_set<Attribute*>m_babaAtributes;//static attributes for all babas


private:
};