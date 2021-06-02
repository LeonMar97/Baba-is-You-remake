#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Animation.h"
#include "Board.h"
#include "Textures.h"
class Baba : public BaseObject{
	//--------------public--------functions-----------------------//
public:
	Baba();//constractor for static member
	void draw(sf::RenderWindow& window, float deltaTime);
	//--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//		
private:
	
};