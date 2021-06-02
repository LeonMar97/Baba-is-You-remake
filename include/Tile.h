#pragma once
#include "BaseObject.h"
#include <stdlib.h>
#include<list>
#include <SFML/Graphics.hpp>

class Tile {

private:
	std::list<BaseObject*>m_baseObjects;
	sf::Vector2u m_loc;
public:
	Tile() = default;
	Tile(const sf::Vector2u&);
	void addObj(BaseObject*);
	void drawObj(sf::RenderWindow& window, float deltaTime);
};