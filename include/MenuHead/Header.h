#pragma once
#include "Animation.h"
#include <string>
#include<array>
#include<map>
#include <sstream> 

class Header{
public:
	Header(std::stringstream sentecnce);
	std::vector<std::unique_ptr<sf::Sprite>>m_sprites;

private:
	std::vector<Animation>m_animations;
	std::map<char, GameObjects>m_charToEnum;
	//std::vector<>m_sentenceVec;
};