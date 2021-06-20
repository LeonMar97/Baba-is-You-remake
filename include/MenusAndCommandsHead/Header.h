#pragma once
#include "Animation.h"
#include <string>
#include<array>
#include<map>
#include <sstream> 

class Header{
public:
	Header(std::stringstream word, const sf::Vector2f& startPosOfSentence, const sf::Vector2f& scaling, const sf::Color& cr);
	std::vector<Animation>m_animations;
	std::vector<std::unique_ptr<sf::Sprite>>m_sprites;
	void draw( sf::RenderWindow& drawingToWindow);
	const sf::Vector2f wordEnd();
private:
	sf::Clock m_clock;
	void setArt(const sf::Vector2f& startPosOfSentence, const sf::Vector2f& scaling, const sf::Color& cr);
	std::map<char, GameObjects>m_charToEnum;
	//std::vector<>m_sentenceVec;
};