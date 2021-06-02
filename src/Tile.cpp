#include "Tile.h"

Tile::Tile(const sf::Vector2u& loc)
	:m_loc(loc), m_baseObjects(0)
{}
	
void Tile::addObj(BaseObject* baseObj) {
	m_baseObjects.push_back(baseObj);
}

void Tile::drawObj(sf::RenderWindow& window, float deltaTime) {
	m_baseObjects.front()->draw(window, deltaTime, m_loc);
}
