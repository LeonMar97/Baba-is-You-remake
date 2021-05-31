#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Textures {
	//--------------public--------functions-----------------------//
public:
	static Textures& instance();
	//gets requested sound from sound member
	const sf::Texture& get_Textures(gameTextures key) { return (m_gameTex[key]); }
	//--------------private--------functions-----------------------//		
private:
	void loadPic(sf::Texture&, const std::string&, gameTextures curpipe);
	//------------------members-----------------------------------//		
private:
	Textures();//constractor for static member
	//~Textures();
	std::map<enum gameTextures, sf::Texture> m_gameTex;
};