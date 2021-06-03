#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Animation.h"
#include "Board.h"
#include "Textures.h"
class Baba : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Baba(const sf::Vector2u& loc);//constractor for static member
	//void draw(sf::RenderWindow& window, float deltaTime);
	bool move(Board* board, BaseObject*, const sf::Vector2i&);
	bool onMove(Board* board, const sf::Vector2i&);
	//--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//		
private:
	
};