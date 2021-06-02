#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
#include "Textures.h"
//base class for every object on the screen
class BaseObject {

public:
	BaseObject(const sf::Texture& tex, const sf::Vector2u& imgCountAnim);
	void draw(sf::RenderWindow& window, float deltaTime, const sf::Vector2u&);
protected:
	sf::RectangleShape m_character;
	Animation m_animation;
private:
	
};