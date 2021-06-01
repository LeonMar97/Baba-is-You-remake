#pragma once
#include <SFML/Graphics.hpp>
//base class for every object on the screen
class BaseObject {

public:
	void draw(sf::RenderWindow& window, float deltaTime);


private:
	sf::Sprite m_baseObj;
	sf::RectangleShape m_character;
	Animation m_animation;
};