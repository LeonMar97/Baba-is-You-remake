#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
//base class for every object on the screen
class BaseObject {

public:
	BaseObject(const Animation& animation);
	void draw(sf::RenderWindow& window, float deltaTime);


private:
	sf::Sprite m_baseObj;
	sf::RectangleShape m_character;
	Animation m_animation;
};