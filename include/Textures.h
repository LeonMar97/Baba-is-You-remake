#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Textures {
	//--------------public--------functions-----------------------//
public:
	static Textures& instance();
	//gets requested sound from sound member
	const sf::Texture& get_Textures(pipeTextures key) { return (m_pipeTex[key]); }
	//--------------private--------functions-----------------------//		
private:
	void loadPic(sf::Texture&, const std::string&, pipeTextures curpipe);
	//------------------members-----------------------------------//		
private:
	Textures();//constractor for static member
	//~Textures();
	std::map<enum pipeTextures, sf::Texture> m_pipeTex;

};
