#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Baba {
	//--------------public--------functions-----------------------//
public:
	static Baba& Baba& instance();
	//gets requested sound from sound member
	const sf::Baba& get_me();
	//--------------private--------functions-----------------------//		
private:
	//void loadPic(sf::Texture&, const std::string&, GameTextures curpipe);
	//------------------members-----------------------------------//		
private:
	Baba();//constractor for static member
	
	
};