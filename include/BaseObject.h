#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
#include "Textures.h"
//base class for every object on the screen
class Board;
class BaseObject {

public:
	BaseObject(const sf::Texture& tex, const sf::Vector2u& imgCountAnim, const sf::Vector2u&);
	void draw(sf::RenderWindow& window, float deltaTime);
	virtual bool move(Board* board, BaseObject*, const sf::Vector2i&) = 0;
	virtual bool onMove(Board* board, const sf::Vector2i&) { return false; }
protected:
	sf::RectangleShape m_character;
	Animation m_animation;
private:
};