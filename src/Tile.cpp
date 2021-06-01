#include "Tile.h"

void Tile::addObj(BaseObject* baseObj) {
	m_baseObjects.push_back(baseObj);
}

void Tile::drawObj(sf::RenderWindow& window, float deltaTime) {
	m_baseObjects.front()->draw(window, deltaTime);
}
