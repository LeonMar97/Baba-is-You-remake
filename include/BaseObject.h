#pragma once
#include <SFML/Graphics.hpp>
//base class for every object on the screen
class BaseObject {

public:
	void setTexture(const sf::Texture& pic);


private:
	sf::Sprite m_baseObj;
	
};