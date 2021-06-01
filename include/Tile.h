#pragma once
#include "BaseObject.h"
#include <stdlib.h>
#include<list>
#include <SFML/Graphics.hpp>

class Tile {

private:
	std::list<BaseObject*>m_baseObjects;
public:
	void addObject(BaseObject*);
	void drawObj(sf::RenderWindow& window);
};