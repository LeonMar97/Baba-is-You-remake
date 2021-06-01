#pragma once
#include <SFML/Graphics.hpp>
//class for handling Animation
//was taken from https://youtu.be/Aa8bXSq5LDE

class Animation {
public:
	Animation(const sf::Texture& tex, const sf::Vector2u imageCount);
private:
	sf::Vector2u m_imgCount;
	sf::Vector2u m_curImg;

	float m_totalTime;
	float m_switchTime;

public:
	sf::IntRect	 texRect;
	void update(int row, float deltaTime);
};