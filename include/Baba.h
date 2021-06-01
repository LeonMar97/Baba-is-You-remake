#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Animation.h"
#include "Board.h"
#include "Textures.h"
class Baba {
	//--------------public--------functions-----------------------//
public:
	static Baba&  instance();
	//bool movment(Board& b, Dir dir);//will move every instence to the requested direction if posible

	//--------------private--------functions-----------------------//		

	//------------------members-----------------------------------//		
private:
	Baba();//constractor for static member
	Animation m_animation;

	
};