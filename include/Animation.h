#pragma once
#include <SFML/Graphics.hpp>
//class for handling Animation
//was taken from https://youtu.be/Aa8bXSq5LDE

class Animation {
public:
	Animation(sf::Texture* tex, sf::Vector2u imageCount, float switchTime);
private:
	sf::Vector2u m_imgCount;
	sf::Vector2u m_curImg;

	float m_totalTime;
	float m_switchTime;

public:
	sf::IntRect	 texRect;
	void update(int row, float deltaTime);
};