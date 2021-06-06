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
	void move(const sf::Vector2i&);
	bool collidesWith(BaseObject*);
	void handleCollision(Board *board, BaseObject* obj);
	//virtual bool onMove(Board* board, const sf::Vector2i&) { return false; }

protected:
	sf::RectangleShape m_character;
	Animation m_animation;
private:
	sf::Vector2f m_lastPos;
	sf::Vector2f m_currentPos;
};